#include <iostream>
#include <string>
#include <vector>

#define MAXIMUM_ROWS 20
#define MAXIMUM_COLS 20
#define MAXIMU_MATRIXES 25
using namespace std;

struct matrix_struct
{
    string name;
    int rows = 0;
    int cols = 0;
    // vector<int> elements;
    int elements[MAXIMUM_ROWS][MAXIMUM_COLS];
    bool is_square = false;
};

size_t num_current_matrix = 0;
matrix_struct matrixes[MAXIMU_MATRIXES];


//For inserting one by one
void insertElements_singular()
{
    // int num_of_els = matrixes[num_current_matrix].rows * matrixes[num_current_matrix].cols;
    cout << "-----------------------" << endl;
    cout << "Now Inserting One By One : " << endl;

    for (size_t i = 0; i < matrixes[num_current_matrix].rows; i++)
    {
        for (size_t j = 0; j < matrixes[num_current_matrix].cols; j++)
        {
            cout << "Element"
                 << "[" << i << "]"
                 << "[" << j << "]"
                 << " :" << endl;
            cin >> matrixes[num_current_matrix].elements[i][j];
        }
    }
}

// Gets the elements of matrix from the command string like [1,2,3,4,5,...]
void insertElements_multiple(string elements) // elements : [a1,a2,a3,...]
{

    elements.erase(elements.begin());

    cout << elements << endl;

    size_t deli_pos = 0;
    string deli = ",";
    string parsed_number;

    int i = 0, j = 0; // keeping track of matrix elements
    while (deli_pos != string::npos)
    {
        deli_pos = elements.find(deli);               // finding the posistion of the first delimeter = ","
        parsed_number = elements.substr(0, deli_pos); // Extracting the word
        cout << "Parsed word: " << parsed_number << endl;
        elements.erase(0, deli_pos + 1);

        cout << stoi(parsed_number) << endl;
        matrixes[num_current_matrix].elements[i][j] = stoi(parsed_number); // Converting string to int then copying to matrix

        ++j;
        if (j >= matrixes[num_current_matrix].cols)
        {
            j = 0;
            ++i;
        }
    }
}
//Shows the matrix
void showMatr(string name)
{
    cout << "------------Show-------------" << endl;
    for (size_t i = 0; i <= num_current_matrix; i++)
    {
        if (matrixes[i].name == name)
        {
            for (size_t j = 0; j < matrixes[i].rows; j++)
            {
                for (size_t k = 0; k < matrixes[i].cols; k++)
                {
                    cout << matrixes[i].elements[j][k] << " ";
                }
                cout << endl;
            }
            cout << "---------EndShow-------------" << endl;
            break;
        }
    }
}

void is_diagonal(string name)
{
    for (size_t i = 0; i < num_current_matrix; i++)
    {
        if (matrixes[i].name == name)
        {
            if (matrixes[i].is_square == 1)
            {
                bool is_diagonal = true;
                int sum_full = 0;
                int sum_diag = 0;

                for (size_t j = 0; j < matrixes[i].rows; j++)
                {
                    for (size_t k = 0; k < matrixes[i].cols; k++)
                    {
                        sum_full += matrixes[i].elements[j][k];
                    }
                }

                for (size_t j = 0; j < matrixes[i].rows; j++)
                {
                    for (size_t k = 0; k < matrixes[i].cols; k++)
                    {
                        if (j == k)
                            sum_diag += matrixes[i].elements[j][k];
                    }
                }

                if (sum_diag == sum_full)
                {
                    cout << "Yes" << endl;
                    break;
                }
                else
                {
                    cout << "No" << endl;
                    break;
                }
            }
        }
        if (i == num_current_matrix - 1)
        {
            cout << "No Matches Found" << endl;
            break;
        }
    }
}

bool is_upper_triangular(string name)
{
    int sum_upper = 0;
    for (size_t i = 0; i < num_current_matrix; i++)
    {
        if(matrixes[i].name == name)
        {
            if(matrixes[i].is_square)
            {
                for (size_t j = 0; j < matrixes[i].rows ; j++)
                {
                    for (size_t k = 0; k < matrixes[i].cols ; k++)
                    {
                        if(j < k)
                        {
                            sum_upper += matrixes[i].elements[j][k];
                        }
                    }

                }
            }

            if(sum_upper == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    
}

bool is_lower_triangular(string name)
{
    int sum_lower = 0;
    for (size_t i = 0; i < num_current_matrix; i++)
    {
        if(matrixes[i].name == name)
        {
            if(matrixes[i].is_square)
            {
                for (size_t j = 0; j < matrixes[i].rows ; j++)
                {
                    for (size_t k = 0; k < matrixes[i].cols ; k++)
                    {
                        if(j > k)
                        {
                            sum_lower += matrixes[i].elements[j][k];
                        }
                    }

                }
            }

            if(sum_lower == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    
}

bool is_identity(string name)
{
    int sum_diag = 0;
    for (size_t i = 0; i < num_current_matrix ; i++)
    {
        if(matrixes[i].name == name)
        {
            if(matrixes[i].is_square)
            {
                for (size_t j = 0; j < matrixes[i].rows ; j++)
                {
                    for (size_t k = 0; k < matrixes[i].cols ; k++)
                    {
                        if(j == k)
                        {
                            sum_diag += matrixes[i].elements[j][k];
                        }
                    }

                }
            }
            if(sum_diag == matrixes[i].rows)
            {
                return true;
            }
            else
            {
                return false;
            }
            
        }
    }
    
}

int input()
{
    bool close_the_input_function = false; // In case we need to stop the loop in main

    string input_command;      // For storing the input command from the user
    string cm = input_command; // Copying to not lose the original string

    string delimeter = " ";      // This is the seperator of our words
    getline(cin, input_command); // We input the whole line, this way the white spaces are in the string.

    string parsed;          // The parsed string from each parsing action
    size_t dl_position = 0; // Delimeter position - used for erasing before the delimeter /  and for checking if we found all the delimeters with std::npos
    // flags
    bool flag_add = false;
    bool flag_matrix = false;

    // matrix datas state flags
    bool got_name = false;
    bool got_rows = false;
    bool got_cols = false;
    bool got_elements = false;

    // Loop for getting each word out
    while (dl_position != string::npos)
    {
        //Parsing each word
        dl_position = input_command.find(delimeter);   // finding the posistion of the first delimeter = " "
        parsed = input_command.substr(0, dl_position); // Extracting the word
        // cout <<"Parsed word: "<< parsed << endl;
        input_command.erase(0, dl_position + 1); // We erase before the delimeter so the loop works Ex: Hello Ali --> Ali

        if (parsed == "add")
        {
            flag_add = true; // so if the second parsed word is matrix we can add a matrix
            continue;
        }

        if (parsed == "matrix" && flag_add)
        {
            flag_matrix = true;
            continue;
        }

        // Get the name of the matrix
        if (flag_matrix && flag_add)
        {
            if (got_name == false)
            {
                matrixes[num_current_matrix].name = parsed;
                got_name = true;
                //cout << "//GOT NAME : " << matrixes[num_current_matrix].name << endl;
                continue;
            }
        }
        // GET THE ROW
        if (got_name)
        {
            // if there is only the row number at last input then we just go straight to getting the elements with funtion insertElements_singular
            if (dl_position == string::npos && got_rows == false) // if we are at the last word - if we didn't find any white spaces
            {
                matrixes[num_current_matrix].rows = stoi(parsed);
                got_rows = true;
                matrixes[num_current_matrix].cols = matrixes[num_current_matrix].rows;
                got_cols = true;
                matrixes[num_current_matrix].is_square = true;
                insertElements_singular();

                num_current_matrix++;
                break;
            }
            else if (got_rows == false)
            {
                matrixes[num_current_matrix].rows = stoi(parsed);
                cout << matrixes[num_current_matrix].rows << endl;
                got_rows = true;
                continue;
            }
        }
        // GET THE COLUMN
        if (got_rows)
        {
            //If there is a bracket the Matrix is square.
            // Then we pass the parsed bracket to the suitable function to get the elements from it.
            if (parsed.find("[") != string::npos && got_cols == false)
            {
                cout << "Found [" << endl;
                matrixes[num_current_matrix].cols = matrixes[num_current_matrix].rows;
                got_cols = true;
                matrixes[num_current_matrix].is_square = true;

                insertElements_multiple(parsed);
                showMatr(matrixes[num_current_matrix].name);
                cout << "Square ! - type 2 - muliple" << endl;

                num_current_matrix++;
                break;
            }
            else if (got_cols == false)
            {
                matrixes[num_current_matrix].cols = stoi(parsed);
                got_cols = true;
                continue;
            }
        }
        //GET THE ELEMENTS
        if (got_cols)
        {
            if (matrixes[num_current_matrix].rows == matrixes[num_current_matrix].cols) // Checking if the matrix is square.
                matrixes[num_current_matrix].is_square = 1;                             // Changin it to be a square one

            cout << "In getting elements" << endl;
            cout << parsed << endl;
            cout << input_command << endl;
            cout << dl_position << endl;

            if (parsed.find("[") != string::npos)
            {
                cout << "Found [" << endl;
                got_elements = true;

                insertElements_multiple(parsed);
                showMatr(matrixes[num_current_matrix].name);

                cout << "Rectang - type 2 - Multiple" << endl;
                cout << "--------------------------------" << endl;
                cout << "Name : " << matrixes[num_current_matrix].name << endl;
                cout << "Rows : " << matrixes[num_current_matrix].rows << endl;
                cout << "Columns : " << matrixes[num_current_matrix].cols << endl;
                cout << "Square : " << matrixes[num_current_matrix].is_square << endl;
                cout << "--------------------------------" << endl;

                num_current_matrix++;
                break;
            }
            else if (got_elements == false)
            {
                insertElements_singular();
                showMatr(matrixes[num_current_matrix].name);

                cout << "Rectang - type 1 - Singular" << endl;
                cout << "--------------------------------" << endl;
                cout << "Name : " << matrixes[num_current_matrix].name << endl;
                cout << "Rows : " << matrixes[num_current_matrix].rows << endl;
                cout << "Columns : " << matrixes[num_current_matrix].cols << endl;
                cout << "Square : " << matrixes[num_current_matrix].is_square << endl;
                cout << "--------------------------------" << endl;

                num_current_matrix++;
                break;
            }
        }

        if(parsed == "show")
        {
            dl_position = input_command.find(delimeter);   // finding the posistion of the first delimeter = " "
            parsed = input_command.substr(0, dl_position); // Extracting the word
            input_command.erase(0, dl_position + 1);

            showMatr(parsed);
            break;
        }
        // is_diagonal :
        if (parsed == "is_diagonal")
        {
            dl_position = input_command.find(delimeter);   // finding the posistion of the first delimeter = " "
            parsed = input_command.substr(0, dl_position); // Extracting the word
            input_command.erase(0, dl_position + 1);

            is_diagonal(parsed);
            break;
        }

        // is_triangular
        if (parsed == "is_triangular")
        {
            dl_position = input_command.find(delimeter);   // finding the posistion of the first delimeter = " "
            parsed = input_command.substr(0, dl_position); // Extracting the word
            input_command.erase(0, dl_position + 1);

            if(is_upper_triangular(parsed) && is_lower_triangular(parsed))
            {
                cout << "It's both upper and lower triangular" << endl;
            }
            else if(is_upper_triangular(parsed))
            {
                cout << "It's upper triangular" << endl;
            }
            else if (is_upper_triangular(parsed))
            {
                cout << "It's lower triangular" << endl;
            }
            else
            {
                cout << "It's neither lower or upper triangular" << endl;
            }
            
            break;
        }

        // is_upper_triangular
        if (parsed == "is_upper_triangular")
        {
            dl_position = input_command.find(delimeter);   // finding the posistion of the first delimeter = " "
            parsed = input_command.substr(0, dl_position); // Extracting the word
            input_command.erase(0, dl_position + 1);

            if(is_upper_triangular(parsed))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            
            break;
        }

        // is_lower_triangular
        if (parsed == "is_lower_triangular")
        {
            dl_position = input_command.find(delimeter);   // finding the posistion of the first delimeter = " "
            parsed = input_command.substr(0, dl_position); // Extracting the word
            input_command.erase(0, dl_position + 1);

            if(is_lower_triangular(parsed))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            
            break;
        }

        // is_identity
        if(parsed == "is_identity")
        {
            dl_position = input_command.find(delimeter);   // finding the posistion of the first delimeter = " "
            parsed = input_command.substr(0, dl_position); // Extracting the word
            input_command.erase(0, dl_position + 1);

            if(is_identity(parsed))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }

            break;
        }

    }
}

int main()
{
    while (1)
    {
        input();
    }

    return 0;
}