

/**
* @ProgramName: Program-1
* @Author: Vahini Nareddy 
* @Description: 
*     This program reads in images stored as rgb values in a space delimited file format.Based on user input, respective function gets executed and turns image vertically,horizontally or grayScale.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 05 02 2017
*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

/**
Structure to hold an rgb value
*/
struct rgb{
    int r;
    int g;
    int b;
};

/**
Changes all rgb values with newcolor rgb values and changes color of image to newcolor.
*/

void changeColor(rgb** image,int width, int height, rgb newColor){
   // loop through image
   // assign newColor to each location in array
   newColor.r=255;
   newColor.g=255;
   newColor.b=51;
  
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
          
image[i][j].r = newColor.r;
image[i][j].g = newColor.g;
image[i][j].b = newColor.b;
            
            
        }
       
        
    }
}

/**
* @FunctionName: grayScale
* @Description: 
*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/

void grayScale(rgb** image,int width,int height){

    for(int i=0;i<height;i++){
      for(int j=0;j<width;j++){
        int gray = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
        image[i][j].r = gray;
        image[i][j].g = gray;
        image[i][j].b = gray;
     
            
        }
        
    }
}

/**
* @FunctionName: flipHorz
* @Description: 
*     Loops through a 2D array and interchanges columns and then turns image horizontally..
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/

void flipHorz(rgb** image,int width,int height){
    
    ifstream ifile;          //Input / output files
    ifile.open("input.txt");
    rgb **newimage;
    int temp;
    ifile>>width>>height;
    newimage = new rgb*[height];    //This array points to every row
    
    for(int i=0;i<height;i++){
        newimage[i] = new rgb[width]; //Now allocate each row of rgb's
    }
    
    //Read the color data in from our txt file
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ifile>>newimage[i][j].r>>newimage[i][j].g>>newimage[i][j].b;            
        }
    }
   
  //swaps columns and new rgb values assigned to newimage.
  
   for(int i=0;i<width/2;i++){
   for(int j=0;j<height;j++){
   
      newimage[j][i].r=image[j][width-i-1].r;
      newimage[j][i].g=image[j][width-i-1].g;
      newimage[j][i].b=image[j][width-i-1].b;
      newimage[j][width-i-1].r=image[j][i].r;
      newimage[j][width-i-1].g=image[j][i].g;
      newimage[j][width-i-1].b=image[j][i].b;
       
        
   }
        }
        
        // assigning newimage rgb values to original image rgb values.
        
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
          
          image[i][j].r=newimage[i][j].r;
          image[i][j].g=newimage[i][j].g;
          image[i][j].b=newimage[i][j].b;
          
        }
        
    }
  
}

/**
* @FunctionName: flipVert
* @Description: 
*     Loops through a 2D array and interchanges rows and then turns image vertically..
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/

void flipVert(rgb** image,int width,int height){
   
      ifstream ifile;          //Input / output files
      ifile.open("input.txt");
      rgb **newimage;
      ifile>>width>>height;
      newimage = new rgb*[height];    //This array points to every row
    
    for(int i=0;i<height;i++){
        newimage[i] = new rgb[width]; //Now allocate each row of rgb's
    }
    
    //Read the color data in from our txt file
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ifile>>newimage[i][j].r>>newimage[i][j].g>>newimage[i][j].b;            
        }
    }
   
   //swaps rows and new rgb values assigned to newimage.
   
   for(int i=0;i<height/2;i++){
   for(int j=0;j<width;j++){
   
      newimage[i][j].r=image[height-i-1][j].r;
      newimage[i][j].g=image[height-i-1][j].g;
      newimage[i][j].b=image[height-i-1][j].b;
      newimage[height-i-1][j].r=image[i][j].r;
      newimage[height-i-1][j].g=image[i][j].g;
      newimage[height-i-1][j].b=image[i][j].b;
       
        
   }
   }
   
    // assigning newimage rgb values to original image rgb values.
        
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
          
          image[i][j].r=newimage[i][j].r;
          image[i][j].g=newimage[i][j].g;
          image[i][j].b=newimage[i][j].b;
          
        }
        
    }
  
}


int main(){
    ifstream ifile;          //Input / output files
    ofstream ofile;
    ifile.open("input.txt");
    ofile.open("output.txt");   
    
    int width;               //width of image
    int height;              //height of image
    rgb newColor;
    rgb **imgArray;//Pointer var for our 2D array 
    int option;         
    
    ifile>>width>>height;   //Read in width and height from top of input file
                            //We need this so we can make the array the right 
                            //size.
    
    imgArray = new rgb*[height];    //This array points to every row
    
    for(int i=0;i<height;i++){
        imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
    }
    
    //Read the color data in from our txt file
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ifile>>imgArray[i][j].r>>imgArray[i][j].g>>imgArray[i][j].b;            
        }
    }
    
    //We could make any changes we want to the color image here
    cout<<"Enter whether you want to flip image horizontally or vertically,or grayScale an image"<<endl;
    cout<<"if horizontally - 1"<<endl;
    cout<<"if vertically - 2"<<endl;
    cout<<"if grayScale - 3"<<endl;
    cin>>option;
    if(option==1)
    {
      flipHorz(imgArray,width,height);
    }
    if(option==2)
    {
      flipVert(imgArray,width,height);
    }
    if(option==3)
    {
      grayScale(imgArray,width,height);
    }
    
    
    //Write out our color data to a new file
    ofile<<width<<" "<<height<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ofile<<imgArray[i][j].r<<" "<<imgArray[i][j].g<<" "<<imgArray[i][j].b<<" ";
        }
        ofile<<endl;
    }
   
    return 0;
}
