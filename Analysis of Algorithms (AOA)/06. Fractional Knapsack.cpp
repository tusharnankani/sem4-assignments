#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef struct {
   int v;
   int w;
   float d;
} Item;

void input(Item items[],int sizeOfItems) {
   cout << "Enter total "<< sizeOfItems <<" item's values and weight" <<
   endl;
   for(int i = 0; i < sizeOfItems; i++) {
      cout << "Enter "<< i+1 << " Value: ";
      cin >> items[i].v;
      cout << "Enter "<< i+1 << " Weight: ";
      cin >> items[i].w;
   }
}

void display(Item items[], int sizeOfItems) {
   int i;
   cout << "values: ";
   for(i = 0; i < sizeOfItems; i++) {
      cout << items[i].v << "\t";
   }
   cout << endl << "weight: ";
   for (i = 0; i < sizeOfItems; i++) {
      cout << items[i].w << "\t";
   }
   cout << endl;
}

bool compare(Item i1, Item i2) {
   return (i1.d > i2.d);
}

float knapsack(Item items[], int sizeOfItems, int W) {
   int i, j, pos;
   Item mx, temp;
   float totalValue = 0, totalWeight = 0;

   for (i = 0; i < sizeOfItems; i++) {
      items[i].d = items[i].v / items[i].w;
   }

   sort(items, items+sizeOfItems, compare);
   for(i=0; i<sizeOfItems; i++) {
      if(totalWeight + items[i].w<= W) {
         totalValue += items[i].v ;
         totalWeight += items[i].w;
      } 
      else {
         int wt = W-totalWeight;
         totalValue += (wt * items[i].d);
         totalWeight += wt;
         break;
      }
   }
   cout << "total weight in bag " << totalWeight<<endl;
   return totalValue;
}

int main() {
   int W,n;
   cout<<"Enter total number of items ";
   cin>>n;
   Item items[n];
   input(items, n);
   cout << "Entered data \n";
   display(items,n);
   cout<< "Enter Knapsack weight \n";
   cin >> W;
   float mxVal = knapsack(items, n, W);
   cout << "Max value for "<< W <<" weight is "<< mxVal;
}
