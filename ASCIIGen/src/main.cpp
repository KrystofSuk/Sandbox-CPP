#include <iostream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "rgb.h"
#include "bmp.h"

using namespace std;

int convertToUInt(const char c){
    return (int)(unsigned char)c;
}

int convertToUInt(const char * c){
    int num = 0;
    for (int i = 0; i != 4; ++i) {
        num |= (int)c[i] << ( i * 8 ); 
    }
    return num;
}

int convertToASCII(const char c){
    return (unsigned char)c;
}

string characters = "@%#*+=-:. ";


int main ( int argc, char* argv[] ) { 
    if(argc != 4){
        cerr << "Wrong number of arguments! Needs 'inputBMP' 'outputfile' 'zoom'" << endl;
        return 0;
    } 
    
    int zoom = 1;    
    if(atoi( argv[3] ) > 0 && atoi( argv[3] ) < 30){
        zoom = atoi( argv[3] );
    }else{
        cerr << "Wrong zoom, it must be between 1-29" << endl;
        return 0;
    }
    ifstream streamImage;

    ifstream::pos_type size;

    streamImage.open( argv[1], ios_base::binary );
    if ( streamImage.is_open() ) 
    {        
        char * memblock;
        streamImage.seekg ( 0, streamImage.end );
        int size = streamImage.tellg();
        streamImage.seekg ( 0, streamImage.beg );

        memblock = new char [size];
        streamImage.read( memblock, size );
        streamImage.close();

        if( convertToASCII( memblock[0] ) == 'B' && convertToASCII( memblock[1]) == 'M' ){  
            char w[4] = { memblock[18], memblock[19], memblock[20], memblock[21] };
            char h[4] = { memblock[22], memblock[23], memblock[24], memblock[25] };
            BMP bmpInfo = BMP( convertToUInt(w) / zoom, convertToUInt(h) / zoom,  convertToUInt(memblock[28] ) );
            int add = convertToUInt(w) % zoom;
            
            //cout << "BMP format: " << size << "/" << bmpInfo.GetX() << "/" << bmpInfo.GetY() << "/" << bmpInfo.GetColorNumber() << endl;
            
            int readerIndex = 54;

            RGB **image = new RGB*[bmpInfo.GetY()];
            
            for(int i = 0; i < bmpInfo.GetY(); i++) {
                image[i] = new RGB[bmpInfo.GetX()];
            }

            for(int y = 0; y < bmpInfo.GetY(); y++){
                for(int x = 0; x < bmpInfo.GetX(); x++){
                    image[bmpInfo.GetY() - 1 - y][x].SET( convertToUInt( memblock[readerIndex + 1] ), convertToUInt( memblock[readerIndex] ), convertToUInt( memblock[readerIndex + 2] ) );
                    readerIndex += 3 * zoom;
                }
                readerIndex += add * 3 + convertToUInt(w) % 4 + ( zoom - 1 ) * ( convertToUInt( w ) * 3 + convertToUInt( w ) % 4 );
            }

            ofstream outfile ( argv[2] );

            for(int y = 0; y < bmpInfo.GetY(); y++){
                for(int x = 0; x < bmpInfo.GetX(); x++){
                    int index = image[y][x].GetGrayscale() * 9;
                    //cout << image[y][x].GetGrayscale() << "|";
                    outfile << characters[index];
                }
                //cout << endl <<endl;
                outfile << endl;
            }

            outfile.close();      
        }


        
        cout << "ASCII art generated!" << endl;        
        delete[] memblock;
    } 
    else 
    {
        cerr << "Unable to open file!" << endl;
        return 0;
    }

    //cout << RGB.GETGRAYSCALE() << endl;

    ofstream os; 
    os.open("outASCII.txt");
    os << "TST";
    os.close();
    cout << "Completed!";
    return 0;
}