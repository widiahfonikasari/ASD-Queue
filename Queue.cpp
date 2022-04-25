#include <iostream>
using namespace std;

//array antrian
int maksimalAntrianArray =5, front = 0, back = 0;

//ruang antrian array
string antrianAtm[5];

//isFull
bool isFullArray(){
    if(back == maksimalAntrianArray){
        return true;
    }else{
        return false;
    }
}

//isEmpty
bool isEmptyArray(){
    if(back == 0){
        return true;
    }else{
        return false;
    }
}

//enqueue
void enqueueArray(string data){
	if(isFullArray() ){
        cout<<"Antrian Penuh!!"<<endl;
    }else{
        if(isFullArray()){
            //kalau antrian kosong
            antrianAtm[0]=data;
            front++;
            back++;
        }else{
            //kalau tidak kosong
            antrianAtm[back]=data;
            back++;
        }
    }
	
}

//dequeue
void dequeueArray(){
    if(isEmptyArray() ){
        cout<<"Antrian Kosong!!"<<endl;
    }else{
       for(int i = 0; i<back; i++){
           antrianAtm[i] = antrianAtm[i+1];
       }
       back--;
    }
}

//countArray
int countArray(){
    if(isEmptyArray()){
        return 0;
    }else if(isFullArray()){
        return maksimalAntrianArray;
    }else{
        return back;
    }
}

//destroy
void destroyArray(){
    if(isEmptyArray() ){
        cout<<"Antrian Kosong!!"<<endl;
    }else{
       for(int i = 0; i<maksimalAntrianArray; i++){
           if(back > 1){
            antrianAtm[i] = "";
            back--;
           }else if(back == 1){
               antrianAtm[back-1]="";
               back = 0;
               front = 0;
           }
       }
    }
}

//Display
void displayArray(){
    cout<<"Jumalah Data Antrian : "<<countArray()<<"data."<
    cout<<"Data Antrian Atm : "<<endl;
    if(isEmptyArray()){
        cout<<"Antrian Kosong!!"<<endl;
    }else{
	for(int i=0; i<maksimalAntrianArray; i++){
	   //kalau ruang tidak kosong
	   if(antrianAtm[i] != ""){
           	//kalau  ruang tidak kosong
	   	cout<<i+1<<". "<<antrianAtm[i]<<endl;
	   }else{
           	//kalau ruang kosong
		cout<<i+1<<". (kosong) "<<antrianAtm[i]<<endl;
	   }
        }
    }
    cout<<"\n"<<endl;
    
}



int main(){
	
    //tambah data
    enqueueArray("Mamat");
    displayArray();

    enqueueArray("Jesi");
    displayArray();

    enqueueArray("Faris");
    enqueueArray("Anna");
    enqueueArray("Jones");
    displayArray();

    enqueueArray("Maria");
    displayArray();

    dequeueArray();
    displayArray();

    dequeueArray();
    displayArray();

    dequeueArray();
    displayArray();
}
