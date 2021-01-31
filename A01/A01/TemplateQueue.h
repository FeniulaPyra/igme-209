#ifndef TEMPLATEQUEUE_H
#define TEMPLATEQUEUE_H
#include <iostream>

using namespace std;

//*spooky voice* ooOOooOOooOO you will pronounce "queue" as "kwee-wee" in your head while reading this code OoOoooo...
template <typename T>
class TemplateQueue {
private: 
	int size;
	int count;
	T* arr;
public:
	//default constructor
	TemplateQueue<T>() {
		size = 2;
		count = 0;
		arr = new T[size]();
	};
	//copy constructor
	TemplateQueue<T>(const TemplateQueue& other) {
		size = other.size;
		count = other.count;
		arr = new T[size]();
		for (int i = 0; i < other.count; i++) {
			arr[i] = other.arr[i];
		}
	};
	//copy assignment
	TemplateQueue& operator= (const TemplateQueue& other){
		size = other.size;
		count = other.count;
		arr = new T[size]();
		for (int i = 0; i < other.count; i++) {
			arr[i] = other.arr[i];
		}
	};
	//destructor
	~TemplateQueue() { 
		arr = NULL;
		delete[] arr;
	}
	



	int GetSize() {
		return count;
	}

	void Push(T item) {
		int i = 0;
		//finds the spot to insert at
		//(if the array is empty, the function will skip this part and return false for the upcoming if statement)
		while (i < count - 1 && item < arr[i]) {
			i++;
		}
		//if the array is too big to fit anymore
		if (count > size) {
			//double the size
			size *= 2;
			T* newArr = new T[size]();
			
			//put everything into the new array
			for (int j = 0; j < i; j++) {
				newArr[j] = arr[j];
			}
			newArr[i] = item;
			for (int j = i; j < count; j++) {
				newArr[j + 1] = arr[j];
			}

			//deletes the old array
			arr = NULL;
			delete[] arr;

			//array is set to new array
			arr = newArr;
		}
		else {

			//inserts the item and shifts everything over;
			//holds onto the item to be inserted
			T insertItem = item;
			for (i = i; i < count; i++) {
			
				//saves the old item so we don't lose it
				T oldItem = arr[i];
				//inserts new item into old item's position
				arr[i] = insertItem;

				//sets the old item to be the new item to be inserted
				insertItem = oldItem;
			}
			//inserts the final item
			arr[count] = insertItem;

		}
		//increments count
		count++;
	}

	//"deletes" the item from the queue and returns the "deleted" item
	T Pop() { //soda

		count--;
		return arr[count + 1];
	}

	void Print() {
		//shows the some info about the array
		cout << "----- begin array" << endl;
		cout << "Type: \t" << typeid(T).name() << endl;
		cout << "items \t" << count << endl;
		cout << "-" << endl;
		//prints the array
		for (int i = count - 1; i >= 0; i--) {
			cout << count - i << ": \t"<< arr[i] << endl;
		}
		cout << "----- end array" << endl;

	}

	//checks if the queue is empty
	bool IsEmpty() {
		return count < 1;
	}
};
#endif  
