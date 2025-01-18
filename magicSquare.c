#include<stdio.h>
int main ()
{
  int n, row, col, diag2, diag1, magicSum = 0;

printf("Enter Size of Matrix: ");
scanf("%d", &n);

if( n < 2) {
  printf("Not possible");
return 0;
}
  
int matrix[n][n];

for(int i = 0; i < n; i ++) {
for(int j = 0; j < n; j++) {
printf("Enter [%d][%d]: ", i + 1, j + 1);
scanf("%d", &matrix[i][j]);
}
}
  
 int isMagic = 1;

for(int j = 0; j < n; j++) {
magicSum += matrix[0][j];
}

for(int i = 1; i < n; i++) {
int row = 0;
for (int j = 0; j < n; j++) {
row += matrix[i][j];
}
}

if (magicSum != row) {
isMagic = 0;
}

for (int j = 0; j < n; j++) {
int col = 0;
for (int i = 1; i < n; i++) {
col += matrix[i][j];
}
}
  
  if (magicSum != col) {
isMagic = 0;
}

for(int j = 0; j < n; j++) {
int diag1 = 0;
diag1 += matrix[j][j];
}

  if (magicSum != diag1) {
isMagic = 0;
}
  
for(int i = 0; i < n; i++) {
int diag2 = 0;
diag2 += matrix[i][n - i - 1];
}

if (magicSum != diag2) {
isMagic = 0;
}

if(isMagic) {
printf("It is a magic square: %d", magicSum);
} else {
printf("It is not a magic square.");
}

return 0;
}
