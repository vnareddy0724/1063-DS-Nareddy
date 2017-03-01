'''cpp
/**
* @Homework: Homework-3
* @Author: Vahini Nareddy 
* @Description: 
*     This program stores values in queue and displays after insertion and deletion.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 01 03 2017
*/

/**
* @FunctionName: Print
* @Description: 
*     If front is less than rear then it prints values from front to rear otherwise if numitems are not empty then it prints values from
Front to last element of array and then get back to starting index of array and then prints till rear.
* @Params:
*    NONE
* @Returns:
*    NONE
*/

void Print(){
  int Index=Front;
  int count=Rear;
  int Rear1=0;
  if(Index < Rear){
   
   while(Index < Rear){
   
    cout<<Q[Index]<<" ";
    Index = (Index+1);
   }
}
else if( NumItems!=0){
  while(Index!=ArraySize ){
    
    cout<<Q[Index]<<" ";
    Index = (Index+1);
    
  while(Index==ArraySize && count !=0 && count < ArraySize){
    
    cout<<Q[Rear1]<<" ";
    
    Rear1++;
    count--;
    
  }
  }
}
}
  
'''
