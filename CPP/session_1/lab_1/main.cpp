#include<stdio.h>
#include<iostream>

using namespace std;

int main(void)
{
    /* this is a double pointer of char to deal with it as array of strings */
    char **string;  
    
    /* this is a variable to store the size that user wants in */
    int string_num = 0;

    cout << "Please Enter the number of strings that you want: ";
    cin >> string_num;


    /* allocating the size that user wants dynamically using malloc function*/
    string = (char **)malloc(string_num * sizeof(char *));
    
    cout << "Let's fill the array of string\n";


    /* this loop used for allocating needed size for the string and also taking strings from the user */
    for(int u = 0; u < string_num; u++)
    {
    	cout << "Please enter the string number: " << (u+1) <<"\n"; 
    	string[u] = (char *)malloc(20) ;
        cin >> *(string + u);
    }
    
    /* this loop used for printing the inserted strings */
    for(int z = 0; z < string_num; z++)
    {
        cout << *(string + z) << "\n";
    } 

 


    return 0;
}
