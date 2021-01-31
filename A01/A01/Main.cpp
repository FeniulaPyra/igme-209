#include "Main.h"
#include "TemplateQueue.h"
#include "Alberto.h"

//(in case the spell didn't work the first time)
//*spooky voice* ooOOooOOooOO you will pronounce "queue" as "kwee-wee" in your head while reading this code OoOoooo...
using namespace std;
int main() {
	
	//int queue
	TemplateQueue<int>* intQueue = new TemplateQueue<int>();
	intQueue->Print();

	for (int i = 0; i < 10; i++) {
		intQueue->Push(i);
	}
	
	//copies int queue
	TemplateQueue<int>* duplicateIntQueue = new TemplateQueue<int>(*intQueue);
	duplicateIntQueue->Print();

	cout <<"popping: " << intQueue->Pop() << endl;
	cout << "showing the int queue..." << endl;
	intQueue->Print();
	cout << "...and the duped int queue to show they are not the same" << endl;
	duplicateIntQueue->Print();


	cout << endl << endl;

	//String queue
	TemplateQueue<string*>* strQueue = new TemplateQueue<string*>();
	strQueue->Push(new string("a"));
	strQueue->Push(new string("b"));
	strQueue->Push(new string("c"));
	strQueue->Print();
	

	cout << endl << endl;

	//char queue
	TemplateQueue<char>* charQueue = new TemplateQueue<char>();
	
	for (int i = 0; i < 3; i++) {
		charQueue->Push("abc"[i]);
	}
	charQueue->Print();

	//show sorting
	charQueue->Push('e');
	charQueue->Push('d');
	charQueue->Print();


	cout << endl << endl;

	TemplateQueue<AlbertoClass>* albertos = new TemplateQueue<AlbertoClass>();

	for (int i = 0; i < 10; i++) {
		albertos->Push(AlbertoClass(i));
	}
	albertos->Print();
	intQueue = NULL;
	duplicateIntQueue = NULL;
	strQueue = NULL;
	charQueue = NULL;
	albertos = NULL;

	delete intQueue;
	delete duplicateIntQueue;
	delete strQueue;
	delete charQueue;
	delete albertos; // :(

}
