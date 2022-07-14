#include <windows.h>
#include <iostream>
#include <list>
#include "draws.h"
using namespace std;
// global Graph
	Graph graph;
	char markText[10];
	vector<int> pathSequence;
	float finalCost;
	// fungsi untuk menandai jalur hasil pencarian
void drawResult(){
	glPushMatrix();
	// gambar edges
	float radius = 15.0f;
	
	for (int i=1; i<pathSequence.size(); i++){
		int sourceIdx = pathSequence.at(i-1);
		int targetIdx = pathSequence.at(i);
		drawLine(
		graph.getNodePosition(),
		sourceIdx,
		targetIdx,
		Vec3(1.0f,0.0f,1.0f),
		radius, 3.0f, true);
	}
	// gambar teks
	sprintf(markText,"%s","start");
	Vec3 position(graph.getNodePosition()[pathSequence.at(0)].getX()+2.0f*radius,
	graph.getNodePosition()[pathSequence.at(0)].getY()+2.0f*radius,
	0.0f);
	drawText(position, Vec3(1.0f,0.0f,1.0f), markText, radius, 2.0f);
	glPopMatrix();
}
// taruh semua obyek yang akan digambar di fungsi display()
void displayGraph(){
	// bersihkan dan reset layar dan buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	// posisikan kamera pandang
	gluLookAt(0.0f, 0.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	// panggil fungsi untuk menggambar obyek
	drawNodes();
	if (!pathSequence.empty())
	drawResult();
	drawEdges();
	drawDistances();
	// tampilkan obyek ke layar
	glutSwapBuffers();
}

// hitung jarak heuristik node asal ke node target misalnya
// menggunakan banyaknya busur minimal dari simpul asal ke target
float computeHeuristic(Graph graph,bool visited[],int startIdx,int endIdx){
	// inisialisasi
	bool* localVisited = new bool[graph.getNumNodes()];
	for (int i=0; i<graph.getNumNodes(); i++)
	localVisited[i] = visited[i];
	// jika simpul asal sudah terhubung ke simpul target
	if (graph.getAdjStatus()[startIdx].at(endIdx))
		return 1.0f;
		// jika sudah sampai di simpul target
		if (startIdx == endIdx)
		return 0.0f;
		// hitung banyaknya busur minimum antara simpul asal dan target
		float distance = 0.0f;
	for (int i=0; i<graph.getAdjNodes()[startIdx].size(); i++){
		int nodeIdx = graph.getAdjNodes()[startIdx].at(i);
		if (!localVisited[nodeIdx]){
			localVisited[nodeIdx] = true;
			distance = 1.0f + computeHeuristic(graph, localVisited,
			nodeIdx, endIdx);
		}
	}
	return distance;
}
// hitung cost perjalanan
float computeCost(Graph graph, int startIdx, int nodeIdx, int endIdx){
	// inisialisasi
	bool* visited = new bool[graph.getNumNodes()];
	for (int i=0; i<graph.getNumNodes(); i++)
	visited[i] = false;
	// hitung jarak g(n)
	float distance2root = 0.0f;
	if (pathSequence.size() > 1)
	for (int i=1; i<pathSequence.size(); i++)
		distance2root += graph.getNodeDistance()[pathSequence.at(i-1)].at(pathSequence.at(i));
	float distance2travel = distance2root + graph.getNodeDistance()[startIdx].at(nodeIdx);
	// hitung jarak h(n)
	float distance2target = computeHeuristic(graph, visited, nodeIdx, endIdx);
	// f(n) = g(n) + h(n)
	return distance2travel + distance2target;
}
// fungsi rekursif dari branch and bound
void AStarRecursive(Graph graph, int startIdx, int endIdx, bool visited[], vector<int> &pathSequence){
	// tandai node sekarang sebagai node yang dikunjungi
	visited[startIdx] = true;
	pathSequence.push_back(startIdx);
	// base untuk berhenti
	if (startIdx == endIdx) return;
	// cari cost minimum dari semua node yang bertetangga dengan node sekarang
	int minIdx;
	float minCost = (float)INT_MAX;
	for (int i=0; i<graph.getAdjNodes()[startIdx].size(); i++){
		int nodeIdx = graph.getAdjNodes()[startIdx].at(i);
		if (!visited[nodeIdx]){
			float cost = computeCost(graph, startIdx, nodeIdx, endIdx);
			if (cost < minCost){
				minCost = cost;
				minIdx = nodeIdx;
				finalCost = minCost;
			}
		}
	}
	// rekursi ke node dengan cost minimum
	AStarRecursive(graph, minIdx, endIdx, visited, pathSequence);
}
// fungsi penerapan branch and bound
void AStar(Graph graph, int startIdx, int endIdx){
	// inisialisasi
	finalCost = 0.0f;
	bool* visited = new bool[graph.getNumNodes()];
	for (int i=0; i<graph.getNumNodes(); i++)
	visited[i] = false;
	pathSequence.clear();
	// terapkan rekursi dari BB
	AStarRecursive(graph, startIdx, endIdx, visited, pathSequence);
	// cetak hasilnya
	cout << "Final solusi = ";
	for (int i=0; i<pathSequence.size(); i++)
	cout << pathSequence.at(i) << " ";
	cout << "= " << finalCost;
}
// kode tester
int main(int argc, char** argv){
	cout<<"\t\t ----------------\n";
	cout<<"\t\t|  ALGORITMA A*  |\n";
	cout<<"\t\t ----------------\n\n";
	int startIdx;
	int endIdx;
	int jmlLevel, jmlNode;
	// inisialisasi graf
	cout<<"Jumlah Level : ";
	cin>>jmlLevel;
	cout<<"Jumlah Node  : ";
	cin>>jmlNode;
	graph.setIsDirected(false);
	graph.setNumLevels(jmlLevel);
	graph.setNumNodes(jmlNode);
	// tambahkan node
	int Indeks[jmlNode], Level[jmlNode], Size[jmlNode];
	for(int i=0; i<jmlNode; i++){
		cout<<"Masukkan Indeks Node ke "<<i+1<<" : ";
		cin>>Indeks[i];
		cout<<"Masukkan Level Node ke "<<i+1<<" : ";
		cin>>Level[i];
		cout<<"Masukkan Size Node ke "<<i+1<<" : ";
		cin>>Size[i];
		cout<<endl;
	}
	for(int j=0; j<jmlNode; j++){
		graph.addNode(Indeks[j], Level[j], Size[j]);
	}
//	graph.addNode(0, 0, 1.0f);
//	graph.addNode(1, 0, 1.0f);
//	graph.addNode(2, 1, 1.0f);
//	graph.addNode(3, 1, 1.0f);
//	graph.addNode(4, 2, 1.0f);
//	graph.addNode(5, 3, 1.0f);
//	graph.addNode(6, 3, 1.0f);
	// tambahkan edge
	cout<<"Masukkan Node relasi : ";
	cin>>jmlNode;
	int tujuan[jmlNode];
	for(int i=0; i<jmlNode; i++){
		cout<<"Masukkan Indeks Node  : ";
		cin>>Indeks[i];
		cout<<"Masukkan tujuan Node ke  : ";
		cin>>tujuan[i];
		cout<<"Masukkan Size Node ke  : ";
		cin>>Size[i];
		cout<<endl;
	}
	for(int j=0; j<jmlNode; j++){
		graph.addEdge(Indeks[j], tujuan[j], Size[j]);
	}
//	graph.addEdge(0, 1, 3.0f);
//	graph.addEdge(0, 3, 5.0f);
//	graph.addEdge(0, 2, 4.0f);
//	graph.addEdge(1, 3, 2.0f);
//	graph.addEdge(2, 4, 4.0f);
//	graph.addEdge(3, 4, 2.0f);
//	graph.addEdge(4, 5, 1.0f);
//	graph.addEdge(4, 6, 6.0f);
//	graph.addEdge(5, 6, 3.0f);
	// estimate node position
	cout<<"Indeks Awal  : ";
	cin>>startIdx;
	cout<<"Indeks Akhir : ";
	cin>>endIdx;
	graph.setNodePosition();
	graph.setAdjStatus();
	// penerapan algoritma A*
	AStar(graph, startIdx, endIdx);
	// inisialisasi jendela OpenGL
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	// set ukuran jendela tampilan dalam piksel
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	// posisi jendela dilayar komputer dalam piksel
	glutInitWindowPosition(100, 100);
	// judul jendela (isi dengan NAMA / NIM - JUDUL PRAKTIKUM)
	glutCreateWindow("RIYAN ADI SAPUTRO / 2000018286 - RESPONSI STRATEGI ALGORITMA");
	// panggil fungsi init untuk inisialisasi awal
	initView();
	// event handler untuk display
	glutDisplayFunc(displayGraph);
	glutReshapeFunc(reshapeView);
	// looping
	glutMainLoop();
	return 0;
}
