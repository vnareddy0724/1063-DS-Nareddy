

/**
* @ProgramName: Program-2
* @Author: Vahini Nareddy
* @Description: 
*     This program reads in images stored as rgb values in a space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 14 02 2017
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


class ImageManip{
private:
    rgb** image;
    int width;
    int height;
    ifstream infile;
    ofstream ofile;
    string ifile_name;
    string ofile_name;
    
    
    /**
* @FunctionName: readFile
* @Description: 
*     Reads all the rgb values from input file and stores in rgb *image...
* @Params:  
*  None   
* @Returns:
*    void
*/
    void readFile(){
      ifile_name="input.txt";
      infile.open(ifile_name);
      infile>>width>>height;   //Read in width and height from top of input file
                            //We need this so we can make the array the right 
                            //size.
    
      image = new rgb*[height];    //This array points to every row
    
      for(int i=0;i<height;i++){
        image[i] = new rgb[width]; //Now allocate each row of rgb's
      }
    
    //Read the color data in from our txt file
      for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            infile>>image[i][j].r>>image[i][j].g>>image[i][j].b;            
        }
      }
      
      
    }
    
   /**
* @FunctionName: writeFile
* @Description: 
*     writes all the rgb values into output file...
* @Params:  
*  None   
* @Returns:
*    void
*/ 
    void writeFile(){
      ofile.open("output.txt"); 
      ofile<<width<<" "<<height<<endl;
      for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ofile<<image[i][j].r<<" "<<image[i][j].g<<" "<<image[i][j].b<<" ";
        }
        ofile<<endl;
    }
      
    }

public:
    ImageManip(){
      readFile();
    }
    

   /**
* @FunctionName: flipVert
* @Description: 
*     Loops through a 2D array and interchanges rows and then turns image vertically..
* @Params:
*    ifile_name - name of input file
*    ofile_name - name of output file
*    
* @Returns:
*    void
*/

    void flipVert(string ifile_name,string ofile_name){

        // your code
        infile.open(ifile_name);
        rgb **newimage;
        infile>>width>>height;
        newimage = new rgb*[height];    //This array points to every row
        
        for(int i=0;i<height;i++){
        newimage[i] = new rgb[width]; //Now allocate each row of rgb's
        }
        
        //Read the color data in from our txt file
        for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
          infile>>newimage[i][j].r>>newimage[i][j].g>>newimage[i][j].b;            
        }
        }
        
        
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
        
        for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
        
        image[i][j].r=newimage[i][j].r;
        image[i][j].g=newimage[i][j].g;
        image[i][j].b=newimage[i][j].b;
        
        }
        
        }
        writeFile();  
    }
   
   /**
* @FunctionName: flipHorz
* @Description: 
*     Loops through a 2D array and interchanges columns and then turns image horizontally..
* @Params:
*    ifile_name - name of input file
*    ofile_name - name of output file
*    
* @Returns:
*    void
*/
   
    void flipHorz(string ifile_name,string ofile_name){
        // your code
        
        infile.open(ifile_name);
        rgb **newimage;
        int temp;
        infile>>width>>height;
        newimage = new rgb*[height];    //This array points to every row
        
        for(int i=0;i<height;i++){
        newimage[i] = new rgb[width]; //Now allocate each row of rgb's
        }
        
        //Read the color data in from our txt file
        for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            infile>>newimage[i][j].r>>newimage[i][j].g>>newimage[i][j].b;            
        }
        }
        
        
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
        
        for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
          
          image[i][j].r=newimage[i][j].r;
          image[i][j].g=newimage[i][j].g;
          image[i][j].b=newimage[i][j].b;
          
        }
        
        }
        writeFile(); 
    }

  /**
* @FunctionName: grayScale
* @Description: 
*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
* @Params:
*    ifile_name - name of input file.
*    ofile_name - name of output file.
*    
* @Returns:
*    void
*/

    void grayScale(string ifile_name,string ofile_name){
        // your code
        for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
        int gray = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
        image[i][j].r = gray;
        image[i][j].g = gray;
        image[i][j].b = gray;
        
            
        }
        
        }
        writeFile();  
    }    
        
    
    
};
int main(){
      int option;
      ImageManip image;
      cout<<"Enter whether you want to flip image horizontally or vertically,or grayScale an image"<<endl;
      cout<<"if horizontally - 1"<<endl;
      cout<<"if vertically - 2"<<endl;
      cout<<"if grayScale - 3"<<endl;
      cin>>option;
      if(option==1)
      {
        image.flipHorz("input.txt","output.txt");
      }
      if(option==2)
      {
        image.flipVert("input.txt","output.txt");
      }
      if(option==3)
      {
        image.grayScale("input.txt","output.txt");
      }
      
      
      return 0;
  
}
