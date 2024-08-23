/*
Simulate the working of Tower of Hanoi for n disks. Print the number of moves.
*/

#include <stdio.h>

void toH(int n, char rodA, char rodC, char rodB){
	if (n == 1){
		printf("\n Move disk 1 from rod %c to rod %c",rodA ,rodC );
		return;
	}
	toH(n-1, rodA, rodB, rodC);
	printf("\n Move disk %d from rod %c to rod %c", n, rodA, rodC);
	toH(n-1, rodB, rodC,rodA);
}

int main(){
	int no_of_disks ;
	printf("Enter number of disks: ");
	scanf("%d", &no_of_disks);
	toH(no_of_disks, 'A','C','B'); 
	return 0;
}

/*
Call Tree

toH(3, 'A', 'C', 'B')
|
|-- toH(2, 'A', 'B', 'C')
|   |
|   |-- toH(1, 'A', 'C', 'B')
|   |   |-- Move disk 1 from rod A to rod C
|   |
|   |-- Move disk 2 from rod A to rod B
|   |
|   |-- toH(1, 'C', 'B', 'A')
|       |-- Move disk 1 from rod C to rod B
|
|-- Move disk 3 from rod A to rod C
|
|-- toH(2, 'B', 'C', 'A')
    |
    |-- toH(1, 'B', 'A', 'C')
    |   |-- Move disk 1 from rod B to rod A
    |
    |-- Move disk 2 from rod B to rod C
    |
    |-- toH(1, 'A', 'C', 'B')
        |-- Move disk 1 from rod A to rod C
*/