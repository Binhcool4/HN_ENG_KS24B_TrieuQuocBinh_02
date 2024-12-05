#include <stdio.h>
int main(){
	int i, j;
	int array[100];
	int n = 0;
	int choice;
	
	do{
		printf("\nMenu\n");
		printf("1.Nhap phan tu va gia tri cua mang\n");
		printf("2.In ra cac gia tri phan tu trong mang\n");
		printf("3.Dem so luong hoan hao co trong mang\n");
		printf("4.Tim gia tri nho thu hai trong mang\n");
		printf("5.Them mot phan tu, chi them phan tu do khi khong ton tai trong mang\n");
		printf("6.Xoa phan tu tai mot vi tri cu the\n");
		printf("7.Sap xep mang theo thu tu tang dan (bubble sort)\n");
		printf("8.Tim kiem phan phan tu co trong mang hay khong\n");
		printf("9.Sap xep mang va hien thi sao cho so le dung truoc, so chan dung sau\n");
		printf("10.Kiem tra xem mang co tang dan hay khong\n");
		printf("11.Thoat chuong trinh.\n");
		printf("Lua chon cua ban: ");
        scanf("%d", &choice);
		
		switch(choice){
			case 1:{
				printf("Nhap so phan tu: ");
                scanf("%d", &n);
                if (n <= 0 || n > 100) {
                    printf("So luong phan tu khong hop le!\n");
                    break;
                }
                for (i = 0; i < n; i++) {
                    printf("Phan tu tai vi tri array[%d]: ", i);
                    scanf("%d", &array[i]);
			    }
			    break;
		    }
			case 2:{
				printf("Cac phan tu trong mang: ");
                for ( i = 0; i < n; i++) {
                    printf(" array[%d] = %d ", i, array[i]);
                }
                printf("\n");
				break;
			}
			case 3:{
				int count = 0;
                for ( i = 0; i < n; ++i) {
                    int sum = 1;
                    for ( j = 2; j * j <= array[i]; ++j) {
                        if (array[i] % j == 0) {
                            if (j == array[i] / j) {
                                sum += j;
                            } else {
                                sum += j + (array[i] / j);
                            }
                        }
                    }
                    if (sum == array[i] && array[i] != 1) {
                        ++count;
                    }
                }
                printf("So luong so hoan hao trong mang: %d\n", count);
				break;
			}
			case 4:{
				
				break;
			}
			case 5:{
				int value;
                printf("Nhap phan ta can them: ");
                scanf("%d", &value);
                if(value == array[100]){
                	printf("So phan tu da co trong mang.\n");
                	break;
				}
                array[n] = value;
                n++;
				break;
			}
			case 6:{
				int index;
                printf("Nhap vi tri phan tu can xoa: ");
                scanf("%d", &index);
                if(index >= 0 && index < n){
                    for ( i = index; i < n - 1; i++) {
                        array[i] = array[i + 1];
                    }
                        n--;
                    }else{
                        printf("Vi tri khong hop le.\n");
                    }
				break;
			}
			case 7:{
				for(i = 0; i < sizeof(array)/sizeof(array[0]); i++ ){
		        for(j = 0; j<sizeof(array)/sizeof(array[0])-i-1; j++){
			    if(array[j] > array[j+1]){
				    int temp = array[j];
				    array[j] = array[j + 1];
				    array[j + 1] = temp;
			      }  
			
		        }
			
	        }
	
	            printf("So nguyen to theo thu tu tang dan la : \n");
	            for(i = 0; i < sizeof(array)/sizeof(array[0]); i++ ){
		        printf("%d ", array[i]);
	        }
	            printf("\n");
				break;
			}
			case 8:{
				int value;
                printf("Nhap phan tu can tim: ");
                scanf("%d", &value);

                int found = 0;
                for ( i = 0; i < n; ++i) {
                    if (array[i] == value) {
                        found = 1;
                        break;
                    }
                }

                if (found) {
                    printf("Phan tu %d co trong mang.\n", value);
                } else {
                    printf("Phan tu %d khong co trong mang.\n", value);
                }
				break;
			}
			case 9:{
				int oddCount = 0, evenCount = 0;
                int odd[n], even[n];

                for ( i = 0; i < n; ++i) {
                    if (array[i] % 2 == 0) {
                        even[evenCount++] = array[i];
                    } else {
                        odd[oddCount++] = array[i];
                    }
                }

                for ( i = 0; i < oddCount; ++i) {
                    array[i] = odd[i];
                }
                for ( i = 0; i < evenCount; ++i) {
                    array[oddCount + i] = even[i];
                }

                printf("Mang sau khi sap xep so le truoc, so chan sau:\n");
                for ( i = 0; i < n; ++i) {
                    printf("%d ", array[i]);
                }
                printf("\n");
				break;
			}
			case 10:{
				int isAsc = 1;
                for ( i = 1; i < n; ++i) {
                    if (array[i] < array[i - 1]) {
                        isAsc = 0;
                        break;
                    }
                }
                if (isAsc) {
                    printf("Mang la mang tang dan.\n");
                } else {
                    printf("Mang khong phai mang tang dan.\n");
                }
				break;
			}
			case 11:{
				printf("Thoat chuong trinh\n");
				break;
			}
			default:{
				printf("Lua chon khong hop le\n");
			}
		}
		
		
	}while(choice != 11);
	
	
	
	return 0;
}
