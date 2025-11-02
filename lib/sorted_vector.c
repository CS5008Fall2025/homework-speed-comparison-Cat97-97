/**
 * Contains functions for the sorted vector struct
 *
 * @author: STUDENT ADD YOUR NAME
 * @class: CS 5008
 * @term: UPDATE WITH CURRENT SEMESTER
**/

#include "vector.h"
#include "movie.h"
#include <strings.h>


/**
 * adds a movie to the sorted vector.
 * 
 * Based on the movie (compare_movies), it will find the correct index
 * using a linear search.
 * 
 * The moment it finds that the movie to add is greater than the
 * current movie, it will insert it at that next index calling vector_insert.
 * 
 * 
 * @param vector the vector to add the movie to
 * @param movie the movie to add
*/
void add_to_sorted_vector(SortedMovieVector * vector, Movie * movie) {
    if (vector == NULL || movie == NULL) {
        return;
    }
    // Linear search to find first index where current > movie, insert before it
    int insert_index = vector->size; // default to end
    for (int i = 0; i < vector->size; i++) {
        if (compare_movies(movie, vector->movies[i]) < 0) {
            insert_index = i;
            break;
        }
    }
    vector_insert(vector, movie, insert_index);
}

/**
 * Finds a movie in the sorted vector based on the title only of the movie.
 *
 * strcasecmp is used to compare the titles, so the search is case insensitive.
 *
 * For example: int cmp = strcasecmp(title, movie->title);
 *
 * You will want to implement this as a binary search. It can be done with a loop
 * or using a helper recursive function (your choice). You are free
 * to add the helper function above if you need one. 
 *
 * @param vector the vector to search
 * @param title the title of the movie to find
 * @return the movie if found, NULL otherwise
 */
Movie * find_in_sorted_vector(SortedMovieVector * vector, const char * title) {
    if (vector == NULL || title == NULL || vector->size == 0) {
        return NULL;
    }
    int left = 0;
    int right = vector->size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        Movie *mid_movie = vector->movies[mid];
        int cmp = strcasecmp(title, mid_movie->title);
        if (cmp == 0) {
            return mid_movie;
        } else if (cmp < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return NULL;
}

/**
 * Checks if the sorted vector contains a movie with the given title.
 *
 * Very similar to find_in_sorted_vector, but instead of just finding
 * the movie will call vector_remove(vector, index) to remove the movie
 * returning the resulted removed movie.
 *
 * You will want to implement this as a binary search. It can be done with a loop
 * or using a helper recursive function (your choice). You are free
 * to add the helper function above if you need one.
 *
 * @param vector the vector to check
 * @param title the title to check for
 * @return the movie removed, NULL otherwise
 */
Movie* sorted_vector_remove(SortedMovieVector *vector, const char *title){
    if (vector == NULL || title == NULL || vector->size == 0) {
        return NULL;
    }
    int left = 0;
    int right = vector->size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcasecmp(title, vector->movies[mid]->title);
        if (cmp == 0) {
            return vector_remove(vector, mid);
        } else if (cmp < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return NULL; // not found
}
