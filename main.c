#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_CAP 10

// Typedefs for the structs
typedef struct Piece Piece;
typedef struct List List;
typedef struct Board Board;

// Structures
struct Piece {
    int rank, file, id;
    Piece * next;
};

struct List {
    int size, cap, id;
    Piece ** arr;
};

struct Board {
    int size, cap;
    List ** arr;
};

// Function prototypes
void addPieceToBoard(Board * board, Piece * piece);
Board * createBoard();
List * createRank();
void addPieceToRank(List * list, Piece * piece);
void expandRank(List * list);
void expandBoard(Board * board);
void destroyBoard(Board * board);
void destroyRank(List * list);
void destroyPiece(Piece * piece);

// Main function
int main() {
    int num_rooks, i;
    
    // Read in the number of rooks
    scanf("%d", &num_rooks);
    
    // Build the data structure
    Board * board = createBoard();
    Piece * piece[num_rooks];
    List * list = createRank();
    
    // User Input
    for (i = 0; i < num_rooks; i++) {
        scanf("%d %d", &piece[i]->rank, &piece[i]->file);
        piece[i]->id = i + 1;
        addPieceToBoard(board, piece[i]);
        addPieceToRank(list, piece[i]);
    }
    printf("\n");
    
    for (i = 0; i < num_rooks; i++) {
        // Find rooks that are below current rook
        if (list->arr[i]->rank < list->arr[i+1]->rank && list->arr[i]->file == list->arr[i+1]->file) {
            
        }
    }
    
    // Clean up the dynamic memory
    destroyBoard(board);

    return 0;
}

// Function to create the Board
Board * createBoard() {
    Board * ret = calloc(1, sizeof(Board));
    
    ret->arr = calloc(DEFAULT_CAP, sizeof(List *));
    ret->size = 0;
    ret->cap = DEFAULT_CAP;
    
    return ret;
}

//Function to create the rank list
List * createRank() {
    List * ret = calloc(1, sizeof(List));
    
    ret->arr = calloc(DEFAULT_CAP, sizeof(Piece *));
    ret->size = 0;
    ret->cap = DEFAULT_CAP;
    ret->id = ret->size + 1;
    
    return ret;
}

// Function to add the piece to the array list
void addPieceToRank(List * list, Piece * piece) {
    // If the array list is full, expand the array list
    if (list->cap == list->size) {
        expandRank(list);
    }
    
    // Add the piece to the end of the array
    list->arr[list->size] = piece;
    
    // Update the number of pieces in the array list
    list->size++;
}

// Function to add the piece to the board
void addPieceToBoard(Board * board, Piece * piece) {
    if (board->cap == board->size) {
        expandBoard(board);
    }
    board->arr[board->size] = createRank();
    board->size++;
}


// Function to expand the rank array list
void expandRank(List * list) {
    int newCap = list->cap * 2;
    
    // Move the pointers of pieces into a new array of pointers
    list->arr = realloc(list->arr, newCap * sizeof(Piece *));
    
    // Update the capacity
    list->cap = newCap;
}

// Function to expand the board array list
void expandBoard(Board * board) {
    int newCap = board->cap * 2;
    
    // Move the pointers of ranks into a new array of pointers
    board->arr = realloc(board->arr, newCap * sizeof(List *));
    
    // Update the capacity
    board->cap = newCap;
}

// Function to destroy the board array list
void destroyBoard(Board * board) {
    // Loop through and destroy each rank
    for(int i  = 0; i < board->size; i++) {
        destroyRank(board->arr[i]);
    }
    
    // Free the array of rank pointers
    free(board->arr);
    
    // Free the actual array list;
    free(board);
}

// Function to destroy the rank array list
void destroyRank(List * list) {
    // Loop through and destroy each piece
    for(int i = 0; i < list->size; i++) {
        destroyPiece(list->arr[i]);
    }
    
    // Free the array of piece pointers
    free(list->arr);
    
    // Free the actual array list
    free(list);
}

// Function to destroy the piece
void destroyPiece(Piece * piece) {
    // Free the pointer
    free(piece);
}

// Function to find the rooks that can attack and prints the output
void findPossibleThreats(Board * board, int n) {
    int i, j;
    
    for(i = 0; i < board->size; i++) {
        List * list = board->arr[i];
        for(j = 0; j < list->size; j++) {
            Piece * current = list->arr[j];
            Piece * temp = list->arr[j];
            
            Piece * attackers;
            Piece * currentAttacker;
            currentAttacker = attackers;
            int attackerCount = 0;
                

            // Find rooks that are below current rook
            if(temp->rank < current->rank && temp->file == current->file) {
                currentAttacker->next = temp;
                currentAttacker = currentAttacker->next;
                attackerCount++;
            }
                    
             // Find rooks that are above current rook
            if(temp->rank > current->rank && temp->file == current->file) {
                currentAttacker->next = temp;
                currentAttacker = currentAttacker->next;
                attackerCount++;
            }
                    
            // Find rooks that are to the right of current rook
            if(temp->rank == current->rank && temp->file < current->file) {
                currentAttacker->next = temp;
                currentAttacker = currentAttacker->next;
                attackerCount++;
            }
                    
            // Find rooks that are to the left of current rook
            if(temp->rank == current->rank && temp->file > current->file) {
                currentAttacker->next = temp;
                currentAttacker = currentAttacker->next;
                attackerCount++;
            }
            temp = list->arr[j];

            printf("%d ", attackerCount);
            currentAttacker = attackers;
            while(currentAttacker != NULL) {
                printf("%d ", attackers->id);
                currentAttacker = currentAttacker->next;
            }
            current = current->next;
            printf("\n");
        }
    }
}
    
