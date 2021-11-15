//Luis Alvear
#include <iostream>
#define Max_el 200 //Defines the max size Size+1
#define Heap_Full(n)	(n==Max_el-1) //Defines when the heap is full
#define Heap_empty (!n) //Defines when the heap is empty
using namespace std;

//Function prototypes
void display(int[],int);
void insertMinH(int[], int&);
void deleteMinH(int[],int&);
int left(int[], int,int);
int right(int[], int,int);
void preorder(int[], int,int);
void postorder(int[], int,int);
void inorder(int[], int,int);

int main()
{
	int heap[Max_el]; //Declares an array of size 200
	//Elements in the heap
	heap[1] = 8; 
	heap[2] = 12;
	heap[3] = 24;
	heap[4]= 32;
	heap[5] = 42;
	int n = 5; //Number of variables that will be incremented after
	int choice; //Holds menu choice
	do {
		//Displays menu
		cout << endl;
		cout << "1. Insert heap: " << endl;
		cout << "2. Delete from heap: " << endl;
		cout << "3. Display preorder and postorder: " << endl;
		cout << "4. Quit." << endl;
		cin >> choice; //User imputs choice
		if (choice == 1)
		{
			insertMinH(heap, n); //Calls the insert min heap function
		}
		if (choice == 2) 
		{
			deleteMinH(heap, n); //Calls the delet min function
			cout << "The element has been deleted..." << endl;
		}
		if (choice == 3)
		{
			cout << "Preorder: "; preorder(heap, 1, n); cout << endl; //Calls the preorder function
			cout << "Postorder: "; postorder(heap, 1, n); cout << endl; //Calls the postorder function
			cout << "Inorder: "; inorder(heap, 1, n); cout << endl; //Calls the inorder function
		}
		if (choice > 4||choice<1)
		{
			cout << "Invalid entry... \n"; 
		}
	} while (choice != 4);
	
}

void insertMinH(int heap[], int &n) //Insertion function
{
	int item; //Holds the value inserted
	
	cout << "Enter a number to insert: "; cin >> item;  //USer inserts value
	if (Heap_Full(n)) //When the heap is full
	{
		exit(1); //Exit
	}
	int i=++n; //We increment the counter, n
	
	while ((i != 1) && (item < heap[i / 2])) //TO insert the value in the correct place
	{
		heap[i] = heap[i / 2]; 
		i /= 2;
	}
	heap[i] = item; //Heap becomes the value inserted
}

void deleteMinH(int heap[], int &n) //Deletion function
{
	int parent = 1; //Holds the parent
	int child = 2; //Holds the child
	int item; //Holds item
	int temp; //Holds temp
	if (n==0) //When n is Null, whe exti
	{
		exit(1);
	}
	temp = heap[n--]; //We decrement the n
	while (child <= n)
	{
		if ((child < n) && heap[child] < heap[child + 1])
			++child; 
		if (temp >= heap[child])
			break;
		heap[parent = heap[child]];
		child *= 2; 
	}
	heap[parent] = temp;  //Temp becomes the new parent because we delete from the top
}

int right(int heap[],int index,int n) //Function that holds the right of the heap
{
	if (heap[index] != '/0' && ((2 * index) + 1 <= n)) //When we want to know the right child we do 2i+1 so if it is correct...
	{
		return (2 * index) + 1; //Return 2i+1
	}
	return -1; //Return -1
}
int left(int heap[], int index,int n) //Function that holds left of the heap
{
	if (heap[index] != '/0' && ((2 * index) <=n)) //THe left child is identified by doing 2*i
	{
		return (2 * index) ; //Returns 2*i
	}
	return -1; //Returns -1
}
void preorder(int heap[], int index,int n) //Function that holds the preorder
{
	if (index>0 &&heap [index]!='\0') //IF heap is not equal to NULL
	{
		cout << heap[index]<<" "; //Displays preorder
		preorder(heap, left(heap, index,n),n); 
		preorder(heap, right(heap, index,n),n);
	}
}
void postorder(int heap[], int index,int n) //Function that holds the postorder
{
	if (index > 0 && heap[index] != '\0') //If heap is not equal to NUll
	{
		preorder(heap, left(heap, index,n),n); 
		preorder(heap, right(heap, index,n),n);
		cout << heap[index]<<" "; //Displays postorder
	}
}
void inorder(int heap[], int index, int n) //Displays the inorder
{
	if (index > 0 && heap[index] != '\0') //IF heap is not equal to NULL
	{
		preorder(heap, left(heap, index,n),n);
		cout << heap[index]<<" "; //DIsplays the inorder
		preorder(heap, right(heap, index,n),n);
	}
}