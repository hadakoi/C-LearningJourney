
#include <stdio.h>
void Mystery(int n){
   if (n <= 0) return;
   printf("%d ", n);
   Mystery(n - 2);
   Mystery(n - 3);
   printf("%d ", n);
}

int main(){
   int number = 5;
   Mystery(number);
}

/*
Mystery(5)
│
├── Print 5
├── Mystery(3)
│   ├── Print 3
│   ├── Mystery(1)
│   │   ├── Print 1
│   │   ├── Mystery(-1) [returns]
│   │   ├── Mystery(-2) [returns]
│   │   └── Print 1
│   ├── Mystery(0) [returns]
│   └── Print 3
├── Mystery(2)
│   ├── Print 2
│   ├── Mystery(0) [returns]
│   ├── Mystery(-1) [returns]
│   └── Print 2
└── Print 5
*/