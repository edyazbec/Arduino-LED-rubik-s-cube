#include <Adafruit_NeoPixel.h>

#define FrontPin 6    // pinout for one half of the cube
#define BackPin 5     // pinout for other half of the cube
#define NUMpixles 27  // number of cubies in each half
#define red 128, 0, 0
#define orange 150, 40, 0
#define yellow 128, 128, 0
#define green 0, 128, 0
#define blue 0, 0, 128
#define white 128, 128, 128
#define delayVal 3000 // Time (in milliseconds) to pause between loops
#define delayMove 1000 // Time (in milliseconds) to pause between moves
char cube[] = "bbbbbbbbbrrrrrrrrryyyyyyyyywwwwwwwwwgggggggggooooooooo"; //solved pattern
//char cube[] = "bgbgbgbgbrororororywywywywywywywywywgbgbgbgbgororororo"; //checkerboard pattern
Adafruit_NeoPixel cubeFront(NUMpixles, FrontPin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel cubeBack(NUMpixles, BackPin, NEO_GRB + NEO_KHZ800);

int transformR[]=
    {0,1,2,   3,4,5,    6,7,8,    //blue
    9,10,29,  12,13,32, 15,16,35, //red
    18,19,11, 21,22,14, 24,25,17, //yellow
    27,28,51, 30,31,48, 33,34,45, //white
    42,39,36, 43,40,37, 44,41,38, //green
    26,46,47, 23,49,50, 20,52,53};//orange
int transformr[]=
    {0,1,2,   3,4,5,    6,7,8,    //blue
    9,10,20,  12,13,23, 15,16,26, //red
    18,19,51, 21,22,48, 24,25,45, //yellow
    27,28,11, 30,31,14, 33,34,17, //white
    38,41,44, 37,40,43, 36,39,42, //green
    35,46,47, 32,49,50, 29,52,53};//orange
int transformU[]=
    {9,10,11, 3,4,5,    6,7,8,    //blue
    36,37,38, 12,13,14, 15,16,17, //red
    24,21,18, 25,22,19, 26,23,20, //yellow
    27,28,29, 30,31,32, 33,34,35, //white
    45,46,47, 39,40,41, 42,43,44, //green
    0,1,2,    48,49,50, 51,52,53};//orange
int transformu[]=
    {45,46,47,  3,4,5,    6,7,8,    //blue
    0,1,2,      12,13,14, 15,16,17, //red
    20,23,26,   19,22,25, 18,21,24, //yellow
    27,28,29,   30,31,32, 33,34,35, //white
    9,10,11,    39,40,41, 42,43,44, //green
    36,37,38,   48,49,50, 51,52,53};//orange
int transformF[]=
    {0,1,27,  3,4,28,   6,7,29,   //blue
    15,12,9,  16,13,10, 17,14,11, //red
    18,19,20, 21,22,23, 8,5,2,    //yellow
    42,39,36, 30,31,32, 33,34,35, //white
    24,37,38, 25,40,41, 26,43,44, //green
    45,46,47, 48,49,50, 51,52,53};//orange
int transformf[]=
    {0,1,26,  3,4,25,   6,7,24,   //blue
    11,14,17,  10,13,16, 9,12,15, //red
    18,19,20, 21,22,23, 36,39,42, //yellow
    2,5,8,    30,31,32, 33,34,35, //white
    29,37,38, 28,40,41, 27,43,44, //green
    45,46,47, 48,49,50, 51,52,53};//orange
int transformL[]=
    {2,5,8,   1,4,7,    0,3,6,    //blue
    27,10,11, 30,13,14, 33,16,17, //red
    9,19,20,  12,22,23, 15,25,26, //yellow
    53,28,29, 50,31,32, 47,34,35, //white
    36,37,38, 39,40,41, 42,43,44, //green
    45,46,24, 48,49,21, 51,52,18}; //orange 
int transforml[]=
    {6,3,0,   7,4,1,    8,5,2,    //blue
    18,10,11, 21,13,14, 24,16,17, //red
    53,19,20, 50,22,23, 47,25,26, //yellow
    9,28,29,  12,31,32, 15,34,35, //white
    36,37,38, 39,40,41, 42,43,44, //green
    45,46,33, 48,49,30, 51,52,27}; //orange
int transformB[]=
    {20,1,2,  19,4,5,   18,7,8,   //blue
    9,10,11,  12,13,14, 15,16,17, //red
    38,41,44, 21,22,23, 24,25,26, //yellow
    27,28,29, 30,31,32, 0,3,6,    //white
    36,37,35, 39,40,34, 42,43,33, //green
    51,48,45, 52,49,46, 53,52,47};//orange
int transformb[]=
    {33,1,2,  34,4,5,   35,7,8,   //blue
    9,10,11,  12,13,14, 15,16,17, //red
    6,3,0,    21,22,23, 24,25,26, //yellow
    27,28,29, 30,31,32, 44,41,38, //white
    36,37,18, 39,40,19, 42,43,20, //green
    47,50,53, 46,49,52, 45,48,51}; //orange
int transformM[]=
    {0,1,2,   3,4,5,    6,7,8,    //blue
    9,19,11,  12,22,14, 15,25,17, //red
    18,52,20, 21,49,23, 24,46,26, //yellow
    27,10,29, 30,13,32, 33,16,35, //white
    36,37,38, 39,40,41, 42,43,44, //green
    45,34,47, 48,31,50, 51,28,53}; //orange
int transformm[]=
    {0,1,2,   3,4,5,    6,7,8,    //blue
    9,28,11,  12,31,14, 15,34,17, //red
    18,10,20, 21,13,23, 24,16,26, //yellow
    27,52,29, 30,49,32, 33,46,35, //white
    36,37,38, 39,40,41, 42,43,44, //green
    45,25,47, 48,22,50, 51,19,53};//orange
int transformE[]=
    {0,1,2,   48,49,50, 6,7,8,    //blue
    9,10,11,  3,4,5,    15,16,17, //red
    18,19,20, 21,22,23, 24,25,26, //yellow
    27,28,29, 30,31,32, 33,34,35, //white
    36,37,38, 12,13,14, 42,43,44, //green
    45,46,47, 39,40,41, 51,52,53};//orange
int transforme[]=
    {0,1,2,   12,13,14, 6,7,8,    //blue
    9,10,11,  39,40,41, 15,16,17, //red
    18,19,20, 21,22,23, 24,25,26, //yellow
    27,28,29, 30,31,32, 33,34,35, //white
    36,37,38, 48,49,50, 42,43,44, //green
    45,46,47, 3,4,5,    51,52,53};//orange
int transformS[]=
    {0,30,2,  3,31,5,   6,32,8,   //blue
    9,10,11,  12,13,14, 15,16,17, //red
    18,19,20, 7,4,1,    24,25,26, //yellow
    27,28,29, 43,40,37, 33,34,35, //white
    36,21,38, 39,22,41, 42,23,44, //green
    45,46,47, 48,49,50, 51,52,53};//orange
int transforms[]=
    {0,23,2,  3,22,5,   6,21,8,   //blue
    9,10,11,  12,13,14, 15,16,17, //red
    18,19,20, 37,40,43, 24,25,26, //yellow
    27,28,29, 1,4,7,    33,34,35, //white
    36,32,38, 39,31,41, 42,30,44, //green
    45,46,47, 48,49,50, 51,52,53};//orange
        
void setup()
{
  char cube[] = "bbbbbbbbbrrrrrrrrryyyyyyyyywwwwwwwwwgggggggggooooooooo"; //solved pattern
  //char cube[] = "bgbgbgbgbrororororywywywywywywywywywgbgbgbgbgororororo"; //chckerboard pattern
  cubeFront.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  cubeFront.clear();  // Set all pixel colors to 'off'
  cubeBack.begin();   // INITIALIZE NeoPixel strip object (REQUIRED)
  cubeBack.clear();   // Set all pixel colors to 'off'
  //initalize the cube colors
    for(int i = 0; i < sizeof(cube); i++)
    {
      if(i <= 26)
      {
        if (cube[i] == 'b')
          cubeFront.setPixelColor(i, cubeFront.Color(blue));
        else if (cube[i] == 'r')
          cubeFront.setPixelColor(i, cubeFront.Color(red));
        else if (cube[i] == 'y')
          cubeFront.setPixelColor(i, cubeFront.Color(yellow));
        else if (cube[i] == 'w')
          cubeFront.setPixelColor(i, cubeFront.Color(white));
        else if (cube[i] == 'g')
          cubeFront.setPixelColor(i, cubeFront.Color(green));
        else if (cube[i] == 'o')
          cubeFront.setPixelColor(i, cubeFront.Color(orange));
      }
      else
      {
        if (cube[i] == 'b')
          cubeBack.setPixelColor(i-27, cubeBack.Color(blue));
        else if (cube[i] == 'r')
          cubeBack.setPixelColor(i-27, cubeBack.Color(red));
        else if (cube[i] == 'y')
          cubeBack.setPixelColor(i-27, cubeBack.Color(yellow));
        else if (cube[i] == 'w')
          cubeBack.setPixelColor(i-27, cubeBack.Color(white));
        else if (cube[i] == 'g')
          cubeBack.setPixelColor(i-27, cubeBack.Color(green));
        else if (cube[i] == 'o')
          cubeBack.setPixelColor(i-27, cubeBack.Color(orange));
      }
    }
  cubeFront.show();
  cubeBack.show();
}

void loop()
{
    delay(delayVal);
    cubeFront.clear();
    cubeBack.clear();
    // eventually, get moves from controller
    //get moves
    // char moves[] = "RUrfRUrurFRRuru"; //jperm
    //char tperm[] = "RUrurFRRuruRUrf"; //tperm
    //char Superflip[] = "MMuRRdSMMUmU2FFdSMMuRRu"; //Superflip
    char moves[] = "";

    for(int j = 0; j < sizeof(moves) - 1; j++)
    {
      delay(delayMove);
      if(moves[j] == 'R')
      {
        char temp[sizeof(cube) - 1];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          temp[i] = cube[transformR[i]];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          cube[i] = temp[i];
      }
      else if(moves[j] == 'r')
      {
        char temp[sizeof(cube) - 1];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          temp[i] = cube[transformr[i]];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          cube[i] = temp[i];
      }
      else if(moves[j] == 'U')
      {
        char temp[sizeof(cube) - 1];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          temp[i] = cube[transformU[i]];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          cube[i] = temp[i];
      }
      else if(moves[j] == 'u')
      {
        char temp[sizeof(cube) - 1];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          temp[i] = cube[transformu[i]];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          cube[i] = temp[i];
      }  
      else if(moves[j] == 'F')
      {
        char temp[sizeof(cube) - 1];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          temp[i] = cube[transformF[i]];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          cube[i] = temp[i];
      }    
      else if(moves[j] == 'f')
      {
        char temp[sizeof(cube) - 1];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          temp[i] = cube[transformf[i]];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          cube[i] = temp[i];
      }
      else if(moves[j] == 'L')
      {
        char temp[sizeof(cube) - 1];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          temp[i] = cube[transformL[i]];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          cube[i] = temp[i];
      }
      else if(moves[j] == 'l')
      {
        char temp[sizeof(cube) - 1];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          temp[i] = cube[transforml[i]];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          cube[i] = temp[i];
      }
      else if(moves[j] == 'B')
      {
        char temp[sizeof(cube) - 1];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          temp[i] = cube[transformB[i]];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          cube[i] = temp[i];
      }
      else if(moves[j] == 'b')
      {
        char temp[sizeof(cube) - 1];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          temp[i] = cube[transformb[i]];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          cube[i] = temp[i];
      }
      else if(moves[j] == 'M')
      {
        char temp[sizeof(cube) - 1];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          temp[i] = cube[transformM[i]];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          cube[i] = temp[i];
      }
      else if(moves[j] == 'm')
      {
        char temp[sizeof(cube) - 1];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          temp[i] = cube[transformm[i]];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          cube[i] = temp[i];
      }
      else if(moves[j] == 'E')
      {
        char temp[sizeof(cube) - 1];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          temp[i] = cube[transformE[i]];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          cube[i] = temp[i];
      }
      else if(moves[j] == 'e')
      {
        char temp[sizeof(cube) - 1];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          temp[i] = cube[transforme[i]];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          cube[i] = temp[i];
      }
      else if(moves[j] == 'S')
      {
        char temp[sizeof(cube) - 1];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          temp[i] = cube[transformS[i]];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          cube[i] = temp[i];
      }
      else if(moves[j] == 's')
      {
        char temp[sizeof(cube) - 1];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          temp[i] = cube[transforms[i]];
        for(int i = 0; i < sizeof(cube) - 1; i++)
          cube[i] = temp[i];
      }

    //update the cube colors
    for(int i = 0; i < sizeof(cube); i++)
    {
      if(i <= 26)
      {
        if (cube[i] == 'b')
          cubeFront.setPixelColor(i, cubeFront.Color(blue));
        else if (cube[i] == 'r')
          cubeFront.setPixelColor(i, cubeFront.Color(red));
        else if (cube[i] == 'y')
          cubeFront.setPixelColor(i, cubeFront.Color(yellow));
        else if (cube[i] == 'w')
          cubeFront.setPixelColor(i, cubeFront.Color(white));
        else if (cube[i] == 'g')
          cubeFront.setPixelColor(i, cubeFront.Color(green));
        else if (cube[i] == 'o')
          cubeFront.setPixelColor(i, cubeFront.Color(orange));
      }
      else
      {
        if (cube[i] == 'b')
          cubeBack.setPixelColor(i-27, cubeBack.Color(blue));
        else if (cube[i] == 'r')
          cubeBack.setPixelColor(i-27, cubeBack.Color(red));
        else if (cube[i] == 'y')
          cubeBack.setPixelColor(i-27, cubeBack.Color(yellow));
        else if (cube[i] == 'w')
          cubeBack.setPixelColor(i-27, cubeBack.Color(white));
        else if (cube[i] == 'g')
          cubeBack.setPixelColor(i-27, cubeBack.Color(green));
        else if (cube[i] == 'o')
          cubeBack.setPixelColor(i-27, cubeBack.Color(orange));
      }
    }
    //display cube
    cubeFront.show();
    cubeBack.show();
  }
}
