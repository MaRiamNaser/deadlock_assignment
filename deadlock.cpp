#include<iostream>
#include<string>
#include<vector>

using namespace std ;


bool calculate_need (int arr1[],int arr2[],int arr3[],int Size)
{
    for (int i = 0 ; i < Size ; i++)
    {
           arr3[i]=arr1[i]-arr2[i];
           if(arr3[i]<0)
           {
              cout << "error occurred because " << arr3[i] << " (the need) less than 0 " << endl ;
              return false;
           }
    }

    return true ;
}



bool compression (int arr1[],int arr2[],int Size)
{
    for (int i = 0 ; i < Size ; i++)
    {
           if(arr1[i]>arr2[i])
           {
              return false;
           }
    }

    return true ;
}


bool Equal (int arr1[],int v,int Size)
{
    for (int i = 0 ; i < Size ; i++)
    {
           if(arr1[i]!=v)
           {
              return false;
           }
    }

    return true ;
}


void addition (int arr1[],int arr2[],int arr3[],int Size)
{
    for (int i = 0 ; i < Size ; i++)
    {
           arr3[i]=arr1[i]+arr2[i];
    }
}

void assignment (int arr1[],int v,int Size)
{
    for (int i = 0 ; i < Size ; i++)
    {
           arr1[i]=v;
    }
}


void input_array (int arr[],int Size,string msg1 , string msg2)
{

    for (int i = 0 ; i < Size ; i++)
    {
            cout << msg1 << i+1 << msg2 ;
            cin >> arr[i];
            cout << endl ;
    }

}

void output_array (int arr[],int Size)
{

    for (int i = 0 ; i < Size ; i++)
    {
            cout << arr[i] << " ";
    }
    cout << endl ;

}




int main()
{

    /*declarations*/
    bool w ;
    bool q = true ;
    int num_of_processes , num_of_resources ;
    ///take number of processes and resources
    cout << endl << "enter number of resources : " ;
    cin >> num_of_resources ;

    cout << endl << "enter number of processes : " ;
    cin >> num_of_processes ;

    ///take available resources
    int available[num_of_resources];
    input_array (available,num_of_resources,"enter available resource "," : ");
    output_array (available,num_of_resources);

    ///take max and allocation for each process
    int maximum     [num_of_processes][num_of_resources] ; //the maximum demand of each process
    int allocation  [num_of_processes][num_of_resources] ; //the amount currently allocated to each process
    int need        [num_of_processes][num_of_resources] ; //the remaining needs of each process

    ///for each process
    for (int i = 0 ; i < num_of_processes ; i++)
    {
        cout << "for process " << i << " :" << endl ;

        ///take the max
        string msg2 = " for process " + to_string(i) + " : " ;
        input_array (maximum[i],num_of_resources,"enter max resource ",msg2);
        output_array (maximum[i],num_of_resources);

        ///take the allocation
        input_array (allocation[i],num_of_resources,"enter allocation resource ",msg2);
        output_array (allocation[i],num_of_resources);

        ///calculate the need = max - allocation
        w = calculate_need (maximum[i],allocation[i],need[i],num_of_resources);
        output_array (need[i],num_of_resources);

    }




    while(q){///begin

    if(w)///if the data is right and every element is positive
    {
    /*the process*/
    int num_of_current_processes = num_of_processes ;
    int num_of_steps = 0 ;
    bool safestate = false ;
    ///vector
    vector <int> vec ;



    for(int i = 0 ; i < num_of_processes ; i++)
    {
        if(compression(need[i],available,num_of_resources) && !Equal(allocation[i],0,num_of_resources)){///if need < available
             ///available = available + allocation[i] ;
             addition(allocation[i],available,available,num_of_resources);
             ///allocation[i] = 0 ;
             assignment(allocation[i],0,num_of_resources);
             num_of_current_processes--;
             num_of_steps = 0 ;
             vec.push_back(i);
             if(num_of_current_processes == 0)
             {
                  safestate = true ;
                  break;
             }


        }

        else
        {
            num_of_steps++;
        }

        if(num_of_steps == num_of_processes)
                break;

        if(i == num_of_processes - 1)
                i = -1;


    }

    ///if safe state -> print safe state + vector
    if(safestate)
    {
        cout << "safe state occurred!!!" << endl ;
        for (int i = 0 ; i < vec.size() ; i++)
        {
            cout << "p" << vec[i] << " " ;
        }
        cout << endl ;
    }

    ///else unsafe state -> print unsafe state
    else
    {
        cout << "unsafe state occurred!!!" << endl ;
    }



    }


    else///data is invalid
    {
        cout << "data is invalid,please enter valid data!!!" << endl ;
    }


    int request ;
j:
    cout << "enter number of process you want to change allocation for OR -1 to finish the program : ";
    cin >> request ;

    if(request == -1)
    {
        q = false ;
        break ;
    }


    else if(request >= 0 && request < num_of_processes)
    {
        string msg2 = " for process " + to_string(request) + " : " ;

        ///change allocation for process[request]
        ///take the allocation
        input_array (allocation[request],num_of_resources,"enter allocation resource ",msg2);
        output_array (allocation[request],num_of_resources);


        ///calculate need
        ///calculate the need = max - allocation
        w = calculate_need (maximum[request],allocation[request],need[request],num_of_resources);
        output_array (need[request],num_of_resources);

    }

    else
    {
        cout << "enter right choice from the above" << endl ;
        goto j ;
    }








}///end

    cout << "made by shihap and mariam , thanks for using our program :)" << endl ;
    return 0 ;
}
