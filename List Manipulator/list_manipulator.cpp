#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
bool isNumber(const string& str){
    for (char const &c : str) {
        if (isdigit(c) == 0) 
            return false;}
    return true;
}

int str_to_int(string str){
    stringstream ss(str);
    int x = 0;
    ss >> x;
    return x;
}

int main(){
    string choice;
    vector<int> list = {};
    
    do {
        
        cout << "\n P  - Print numbers \n A  - Add a number \n Sc - Scan for a number \n M  - Display mean of numbers(average) \n S  - Display the smallest number \n L  - Display the largest number \n C  - Clear the list \n Q  - Quit \n\n Enter the letter regarding your choice: ";
        cin >>  choice;
        
        if  (choice == "P" || choice == "p"){
            if (list.size() == 0)
                cout << "\n [ ] - The list is empty."<<endl;
            else{
            cout << "\n[";
            for (int i = 0 ; i <= (list.size()-1); i++){
                cout << " " << list.at(i);
            }
            cout << " ]\n";}
        }
        else if (choice == "A" || choice == "a"){
            string addition;
            cout << "\n Please enter a number: ";
            cin >> addition;
            bool is_number = false;
            for (auto num : list){
                if (str_to_int(addition) == num){
                    cout << "\n The number you have entered is already in the list!" << endl;
                    is_number = true;}
            }
            while (is_number == false){
                if (isNumber(addition) == true){
                    cout << "\n You have successfully added your number: "<< str_to_int(addition) << endl;
                    list.push_back(str_to_int(addition));
                    is_number = true;
                }
                else{
                    cout << " Please enter a valid number not any other charachter: ";
                    cin >> addition;
                }
            }
        }
        else if (choice == "SC" || choice == "Sc" || choice == "sC" || choice == "sc"){
            string scan;
            cout << "\n Enter a number to scan for: ";
            cin >> scan;
            int count = 1;
            while(true){
                if (isNumber(scan) == true){
                    int cond=0;
                    for (auto num : list){                        
                        if (num == str_to_int(scan)){
                            cond++;
                            cout << "\n The number you have entered is the " << count;
                            if (count%10 == 1)
                                cout << "st element of the list." << endl;
                            else if (count%10 == 2)
                                cout << "nd element of the list." << endl;
                            else if (count%10 == 3)
                                cout << "rd element of the list." << endl;
                            else
                                cout << "th element of the list." << endl;
                        }
                        else{
                            count++;}
                    }
                    if (cond == 0)
                        cout << "\n The number you have entered is not present in the list." << endl;
                    break;
                }
                else{
                    cout << "\n Please enter a number not any other charachter: ";
                    cin >> scan;
                }
            }
        }
        else if (choice == "M" || choice == "m"){
            if (list.size() == 0)
                cout << "\n There is nothing in the list." << endl;
            else if (list.size() == 1 && list.at(0) == 0)
                cout << "\n The mean of the numbers in the list is: 0"<< endl;
            else{
                double total;
                for (auto num: list){
                    total += num;}
                cout << "\n The mean of the numbers in the list is: " << total/list.size() << endl;
            }
        }
        else if (choice == "S" || choice == "s"){
            if (list.size() == 0)
                cout << "\n There is nothing in the list."<< endl; 
            else{
                int smallest = list.at(0);
                for (auto num : list){
                    if(num < smallest)
                        smallest = num;}
                cout << "\n Smallest number in the list is: "<< smallest << endl;  
            }
        }
        else if (choice == "L" || choice == "l"){
            if (list.size()==0)
                cout << "\n There is nothing in the list." << endl;
            else{
                int largest = list.at(0);
                for (auto num: list){
                    if(num > largest)
                        largest = num;}
                cout << "\n The largest number  in the list is: " << largest << endl;
            }
        }
        else if (choice == "C" || choice == "c"){
            list.clear();
            cout << "\n The list has been cleaned." << endl;
        }
        else if (choice == "Q" || choice == "q"){
            cout << "\n Shutting down the program." << endl;
        }
        else{
            cout << "\n Please enter a valid letter!"<< endl;
        }
        
    }while(choice != "Q" && choice != "q");
    
return 0;
}