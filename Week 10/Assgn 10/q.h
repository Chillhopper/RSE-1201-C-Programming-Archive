/*!
@file q.h
@author Kaushik Thirumavalavan (2200927@sit.singaporetech.edu.sh)
@course RSE
@section Year 1
@Assignment 11
@date 18/11/2022
@brief This file contains function declerations for read_data(), max(), min(), average(), variance(), std_dev(), selection_sort(), ltr_grade_pctg()
*//*________________________________________________________________*/

/*!
@brief reads a line from the file and stores it into an allocated memory for future access
@param word - char const *file_name, int *ptr_cnt
@return pointer double to where data is stored
*//*_____________________________________________________________*/
double* read_data(char const *file_name, int *ptr_cnt);

/*!
@brief finds the maximum grade in the array
@param word - double const *begin, double const *end
@return type double value of maximum
*//*_____________________________________________________________*/
double max(double const *begin, double const *end);

/*!
@brief finds the minimum grade in the array
@param word - double const *begin, double const *end
@return type double value of minimum
*//*_____________________________________________________________*/
double min(double const *begin, double const *end);

/*!
@brief finds the average grade in the array
@param word - double const *begin, double const *end
@return type double value of average
*//*_____________________________________________________________*/
double average(double const *begin, double const *end);

/*!
@brief finds the variance in the array
@param word - double const *begin, double const *end
@return type double value of variance
*//*_____________________________________________________________*/
double variance(double const *begin, double const *end);

/*!
@brief finds the standard deviation in the array
@param word - double const *begin, double const *end
@return type double value of standard deviation
*//*_____________________________________________________________*/
double std_dev(double const *begin, double const *end);

/*!
@brief finds median value in the array
@param word - double* base, int size
@return type double of median value
*//*_____________________________________________________________*/
double median(double *base, int size);

/*!
@brief sorts the values in the array in ascending order
@param word - double* base, int size
@return nothing
*//*_____________________________________________________________*/
void selection_sort(double *base, int size);

/*!
@brief calculates percentage of varius grades A,B,C,D and F in the array
@param word - double const *begin, double const *end, double *ltr_grades
@return nothing
*//*_____________________________________________________________*/
void ltr_grade_pctg(double const *begin, double const *end, double *ltr_grades);

/*!
@brief enum with grades A,B,C,D and F
@param word - nothing
@return nothing
*//*_____________________________________________________________*/
enum grades {
    A_GRADE = 0,
    B_GRADE = 1,
    C_GRADE = 2,
    D_GRADE = 3,
    F_GRADE = 4,
    TOT_GRADE = 5
    
};

