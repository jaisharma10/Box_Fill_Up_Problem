/**
 * @file main.cpp
 * @author Jai Sharma (jaisharm@umd.edu)
 * @brief RWA_1: Program Flow Control and Functions
 * @version 0.1
 * @date 2021-09-26
 * 
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <array>

// -----------------------------------------------------------------------//
// Function Prototype
// -----------------------------------------------------------------------//

/**
 * @brief function definition of each function is written below. the box_info 
 * struct is declared here since it is used in 3 of the functions.
 */

struct box_info;

unsigned int get_total_parts();
void get_total_boxes(box_info box[]);
void get_part_per_box(box_info box[]);
void fill_up_boxes(box_info box[]);

// -----------------------------------------------------------------------//
// Data Structures
// -----------------------------------------------------------------------//

/**
 * @brief using struct data structure to store 4 members (XL,L,M,S) in 2 categories 
 * (number of boxes, box capacity)
 */

struct box_info {
     int num_boxes{};
     int parts_per_box{};
};

// -----------------------------------------------------------------------//
// function definitions 
// -----------------------------------------------------------------------//
 
int total_parts = 0; // global variable

/**
 * @brief Gets total numbe of parts to be placed in boxes
 * @return unsigned Number of parts entered by user
 */

unsigned int get_total_parts(){
    do {
    std::cout << "How many parts in total?: ";
    std::cin >> total_parts; 
    if (total_parts <= 0) {
        std::cout << "Try Again. Input must be a positive integer. \n";
    } 
    } while (total_parts <= 0);
    return total_parts;
 }

/**
 * @brief Gets total number of boxes for each box type
 * @param box Data structure holds the Number of 	
 * Boxes information for each box tyoe 
 */

void get_total_boxes(box_info box[]){
    start: std::cout << "How many boxes for S/M/L/XL?: " ;
    for (int i = 0; i <= 3; i++) {
        std::cin >> box[i].num_boxes;
        }
    for (int j = 0; j <= 3; j++) {
        if (box[j].num_boxes < 1){
            std::cout<< "Try Again. All inputs must be positive integers. \n";
            goto start;
        }
     }
}

/**
 * @brief Gets maximum number of parts that each boxes type can store
 * @param box Data structure holds the Number of 	
 * Parts per Box information for each box tyoe 
 */

void get_part_per_box(box_info box[]){
    start: std::cout << "How many parts per box for S/M/L/XL?: " ;
    for (int i = 0; i <= 3; i++) {
        std::cin >> box[i].parts_per_box;
    }
    // Code to check for positive integers
    for (int j = 0; j <= 3; j++) {
        if (box[j].parts_per_box < 1){
            std::cout << "Try Again. All values must be positive. \n";
            goto start;
        }  
    }  
    // Code to check sequence
    for (int k = 1; k <= 3; k++) {
        if (box[k].parts_per_box <= box[k-1].parts_per_box){
            std::cout<<"Try Again. Box capacity values must be ascending in size. \n";
            goto start;               
        }
    }
}

/**
 * @brief Gets the final distribution of boxes required based on user inputs
 * @param box Data structure holds the Number of 	
 * Boxes information for each box tyoe 
 */

void fill_up_boxes( box_info box[]){
    int n_bx = 0; // number of boxes that can be used
    int rem_prts = total_parts; // remaining parts
    int bx_used[4]; // array of boxes used 

    // calculating disttibution
    for(int i = 3;i >= 0;i--){
        int n_bx = rem_prts/box[i].parts_per_box;
        if (n_bx >= 1){
            if (n_bx > box[i].num_boxes){
                bx_used[i] = box[i].num_boxes;
            }
            else {
                bx_used[i] = n_bx;
            }
        }
        else {
            bx_used[i] = 0;
        }
        rem_prts = rem_prts - (bx_used[i]*box[i].parts_per_box);
        // Printing the output
        if (i==3){
            std::cout << "\nBoxes that can be built with " << total_parts << " pegs:" << "\n";
            std::cout << "-----------------------------------------------------" << "\n";
            std::cout << "XL box (" << box[i].num_boxes << " x " << box[i].parts_per_box << " max): " << bx_used[i] << " -- remaining parts: " << rem_prts << "\n";
        }
        if (i==2){
            std::cout << "L box (" << box[i].num_boxes << " x " << box[i].parts_per_box << " max): " << bx_used[i] << " -- remaining parts: " << rem_prts << "\n";
        }
        if (i==1){
            std::cout << "M box (" << box[i].num_boxes << " x " << box[i].parts_per_box << " max): " << bx_used[i] << " -- remaining parts: " << rem_prts << "\n";
        }
        if (i==0){
            std::cout << "S box (" << box[i].num_boxes << " x " << box[i].parts_per_box << " max): " << bx_used[i] << " -- remaining parts: " << rem_prts << "\n";
            std::cout << "Parts not in boxes: " << rem_prts << "\n";
        }
    }
}


// -----------------------------------------------------------------------//
// int main
// -----------------------------------------------------------------------//

/**
 * @brief Int main used to call all functions from above and display final output
 */

int main(){
    box_info box[4];
    get_total_parts(); // call function to get total number of parts
    get_total_boxes(box); // call function to get total number of boxes of each type
    get_part_per_box(box); // call function to get max number of parts per box type
    fill_up_boxes(box); // call function to fill up boxes and to display results
    return 0;
}

// -----------------------------------------------------------------------//

