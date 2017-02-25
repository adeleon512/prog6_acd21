/*
 * prog6_acd21.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: Adam C. De Leon
 *      Discription: This program is designed to calculate a students quiz
 *      average by reading in information from an input file (quiz_info.txt).
 *      The input file contains the quiz number, maximum points possible,
 *      points earned, and add on points. After reading in the information the
 *      program displays the quiz number, the maximum number of points
 *      possible on each quiz and the amount of points earned on each quiz.
 *      The program then prompts the user to enter the number of the quiz they
 *      wish to drop, or a negative number to exit the program, and calculates
 *      and displays the average. Before executing the tasks the program also
 *      verifies that the input file successfully opens with an early return.
 *      Return 1: INput file open error.
 */
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    // Variable and array declarations.
    const int MAX_NUM_QZ = 15;
    int qz_num[MAX_NUM_QZ];
    double max_pts[MAX_NUM_QZ];
    double earned[MAX_NUM_QZ];
    double sum_earned;
    double sum_earned_after_drop;
    double sum_max_pts_after_drop;
    double sum_max_pts;
    double avg;
    int drop_qz;
    double add_on_pts;
    int num_of_quizzes;
    ifstream fin;         // Input file object.

    // Open the input file.
    fin.open("quiz_info.txt");

    // Early return for input file error.
    if (!fin) {
        cout << "The input file failed to open. Make sure it exists in the"
             << " correct location." << endl;
        return 1;
    }

    // Set up data titles.
    cout << "#" << setw(12) << "Max Pts." << setw(9) << "Earned" << endl;
    cout << endl;

    // Read in number of quizzes
    fin >> num_of_quizzes;

    // Initialize values to zero
    sum_earned = 0;
    sum_max_pts = 0;

    //Read in and display arrays.
    for (int i = 0; i < num_of_quizzes; i++) {
        fin >> qz_num[i];
        fin >> max_pts[i];
        fin >> earned[i];

        cout << setprecision(2) << fixed;
        sum_earned = sum_earned + earned[i];
        sum_max_pts = sum_max_pts + max_pts[i];

        cout << qz_num[i] << setw(10) << max_pts[i] << setw(10) << earned[i]
             << endl;
    }

    // Read in add on points.
    fin >> add_on_pts;
    cout << endl;

    //Prompt the user to enter quiz number they wish to drop or negative
    // number to exit program.
    cout << "Enter the quiz number of the one you wish to drop, or a negative"
            " number to exit the program." << endl;
    cin >> drop_qz;

    // calculate average as long as
    while (drop_qz >= 0) {
        avg = 0;
        sum_earned_after_drop = sum_earned - earned[drop_qz];
        sum_max_pts_after_drop = sum_max_pts - max_pts[drop_qz];
        avg = ((sum_earned_after_drop + add_on_pts) / sum_max_pts_after_drop)
              * 100;

        cout << "If you drop quiz " << qz_num[drop_qz] << " your average will "
                "be " << avg << endl;
        cout << endl;
        cout << "#" << setw(12) << "Max Pts." << setw(9) << "Earned" << endl;
        for (int i = 0; i < num_of_quizzes; i++) {
            cout << qz_num[i] << setw(10) << max_pts[i] << setw(10) <<
                 earned[i] << endl;
        }
        cout << endl;

        cout << "Enter the quiz number of the one you wish to drop, or a "
                "or a negative number to exit the program." << endl;
        cin >> drop_qz;
    }

    // Close the output file.
    fin.close();
    return 0;
}



