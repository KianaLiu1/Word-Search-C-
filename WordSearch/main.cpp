#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

//Creating a class for random directions of given words.
class Directions
{
public:
    int HorizontalDirection = rand() % 2;
    int VerticalDirection = rand() % 2;
};

//Creating the grid
char grid[80][80];

//Creating a function of printing the grid
void PrintGrid(int height)
{
    int i,j;
    char letters[80] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    //Create a new txt file to save puzzles
    ofstream CreatedPuzzle;
    CreatedPuzzle.open("FinalOutput.txt",ios::app);
    
    //Fill the grid with random letters
    cout<<endl<<"The Puzzle is"<<endl;
    for(i=0; i<height; i++)
    {
        for(j=0; j<height; j++)
        {
            if(grid[i][j]=='0')
            {
                int RandomLetter = rand() % 26;
                grid[i][j] = letters[RandomLetter];
                
            }
            cout<<grid[i][j];
            //Save the puzzle to the txt file
            CreatedPuzzle<<grid[i][j];
        }
        cout<<endl;
        CreatedPuzzle<<endl;

    }
    cout<<endl;
    CreatedPuzzle<<endl<<endl;
    CreatedPuzzle.close();
    
}

//Create a function of initializing
void InitializeGrid(int height)
{
    int i,j;
    for(i=0; i<height; i++)
    {
        for (j=0; j<height; j++)
        {
            grid[i][j] = '0';
        }
    }

}


int main()
{
    string line[100];
    int height, i, j = 0, g=0, h,WordNumber;
    
    srand(time(NULL));
    
    //Ask for the size of the puzzle and the numer of words
    cout<<"Please enter the height of the puzzle.";
    cin>>height;
    cout<<"How many words do you want to search?";
    cin>>WordNumber;
    
    //Initialize the grid
    InitializeGrid(height);

    //Open the txt file of given words
    ifstream ToBeFound("words.txt");
    
    int len;
    int counter;
    string Replacement;


    if (ToBeFound.is_open())
    {
        //Getline from the txt file
        while (g<WordNumber)
        {
            counter=0;
            getline(ToBeFound, line[g]);
            string Replacement = string(line[g]);
            len=Replacement.length();
            cout<<line[g]<<endl;
            
            //Check if the size of the grid is larger than all the sizes of the words
            if(len>height)
            {
                cout<<"Please enter a larger height"<<endl;
                exit(0);
            }

            //check if the words have found the right position
            while(counter==0)
            {
                //create random position for the first letter of the word
                int RandomPosition1 = rand()% height;
                int RandomPosition2 = rand()% height;
                //Decide if the word is goig forward or backwards
                int ForwardOrBackwards = rand()%2;

                Directions d;
                int k=0;
                
                //if the word is going vertically
                if(d.HorizontalDirection == 0)
                {
                    if(d.VerticalDirection == 1)
                    {
                        i=RandomPosition1;
                        j=RandomPosition2;
                        for(h=0; h<len; h++)
                        {
                            //if the grid is empty
                            if(grid[i][j]=='0')
                            {
                                k++;
                            }
                            //if the grid has the same element as the word
                            if(grid[i][j]==Replacement[h])
                            {
                                k++;

                            }
                            //check if the words is going forward or backwards
                            if(ForwardOrBackwards == 0)
                            {
                                j++;
                            }
                            else
                            {
                                j--;
                            }
                        }
                        //check if the word is positioned properly
                        if (len==k)
                        {
                            i=RandomPosition1;
                            j=RandomPosition2;
                            //Placing the word into the grid
                            for(h=0; h<len; h++)
                            {
                                grid[i][j]=Replacement[h];
                                if(ForwardOrBackwards == 0)
                                {
                                    j++;
                                }
                                else
                                {
                                    j--;
                                }
                            }
                            //break the loop
                            counter = 1;
                            break;
                            
                        }
                        //stay in the loop
                        else
                        {
                            counter = 0;
                        }
                        
                    }
                    //if the word is going no where
                    if(d.VerticalDirection == 0)
                    {
                        //stay in the loop
                        counter=0;
                        
                    }
                    
                }
                
                if(d.HorizontalDirection == 1)
                {
                    //if the word is going horizontally
                    if(d.VerticalDirection == 0)
                    {

                        i = RandomPosition1; j=RandomPosition2;
                        
                        for(h=0; h<len; h++)
                        {
                            
                            if(grid[i][j]=='0')
                            {
                                k++;
                                
                            }
                            if(grid[i][j]==Replacement[h])
                            {
                                k++;
                                
                            }
                            if(ForwardOrBackwards == 0)
                            {
                                i++;
                            }
                            else
                            {
                                i--;
                            }

                        }
                        
                        if (len==k)
                        {
                            i=RandomPosition1;
                            j=RandomPosition2;
                            for(h=0; h<len; h++)
                            {
                                grid[i][j]=Replacement[h];
                                if(ForwardOrBackwards == 0)
                                {
                                    i++;
                                }
                                else
                                {
                                    i--;
                                }
                            }
                            counter = 1;
                            break;
                            
                        }
                        else
                        {
                            counter = 0;
                        }
                        
                        
                        
                    }
                    
                    //if the word is going diagnozely
                    if(d.VerticalDirection ==1)
                    {

                        i = RandomPosition1; j=RandomPosition2;
                        
                        for(h=0; h<Replacement.length(); h++)
                        {
                            
                            if(grid[i][j]=='0')
                            {
                                k++;
                            }
                            if(grid[i][j]==Replacement[h])
                            {
                                k++;
                            }
                            if(ForwardOrBackwards == 0)
                            {
                                j++;
                                i++;
                            }
                            else
                            {
                                j--;
                                i--;
                            }

                            
                            
                        }
                        if (len==k)
                        {
                            i=RandomPosition1;
                            j=RandomPosition2;
                            for(h=0; h<len; h++)
                            {
                                grid[i][j]=Replacement[h];
                                if(ForwardOrBackwards == 0)
                                {
                                    j++;
                                    i++;
                                }
                                else
                                {
                                    j--;
                                    i--;
                                }
                            }
                            counter =1;
                            break;
                            
                        }
                        else
                        {
                            counter = 0;
                        }
                    }
                    
                }
                
                
            }
        
            //move to the next line of the txt file
            g++;
        }
    }
    //Print the grid
    PrintGrid(height);
    
    return 0;
    
    
}

