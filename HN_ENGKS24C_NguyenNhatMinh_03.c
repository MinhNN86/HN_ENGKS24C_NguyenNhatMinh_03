#include <stdio.h>
int main(){
    int mang[100];
    int nguoiDungNhap;
    int check = 0;
    int checkSapXep = 0;
    while(1){
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri cua mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Dem so luong cac so nguyen to co trong mang\n");
        printf("4. Tim gia tri nho thu hai trong mang\n");
        printf("5. Them mot phan tu vao trong mang\n");
        printf("6. Xoa phan tu trong mang\n");
        printf("7. Sap xep mang theo thu tu giam dan\n");
        printf("8. Tim phan tu co trong mang\n");
        printf("9. Xoa toan bo phan tu trung lap trong mang va hien phan tu doc nhat co trong mang\n");
        printf("10. Dao nguoc thu tu cua cac phan tu co trong mang\n");
        printf("11. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &nguoiDungNhap);
        switch(nguoiDungNhap){
            case 1: //Nhap so phan tu va gia tri cua mang
                check = 1;
                int soPhanTu;
                printf("Nhap so phan tu cua mang: ");
                scanf("%d", &soPhanTu);
                if(soPhanTu < 0 || soPhanTu > 100){
                    printf("so phan tu khong hop le");
                    break;
                }
                for(int i = 0; i < soPhanTu; i++){
                    printf("mang[%d]= ", i);
                    scanf("%d", &mang[i]);
                }
                break;
            
            case 2: //In ra gia tri cac phan tu trong mang
                if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
                for(int i = 0; i < soPhanTu; i++){
                    printf("mang[%d]= %d\n", i, mang[i]);
                }
                break;
            
            case 3: //Dem so luong cac so nguyen to co trong mang
                if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
                int checkSoNguyenTo;
                int soLuongSoNguyenTo = 0;
                printf("cac so nguyen to trong mang la: ");
                for(int i = 0; i < soPhanTu; i++){
                    checkSoNguyenTo = 1;
                    if(mang[i] < 2){
                        checkSoNguyenTo = 0;
                    } else {
                        for(int j = 2; j < mang[i]; j++){
                            if(mang[i] % j == 0){
                                checkSoNguyenTo = 0;
                            }
                        }
                    }
                    if(checkSoNguyenTo == 1){
                        soLuongSoNguyenTo += 1;
                        printf("%d ", mang[i]);
                    }
                }
                printf("\nso luong cac so nguyen to trong mang la: ");
                printf("%d ", soLuongSoNguyenTo);
                
                break;
            
        /*    case 4: //Tim gia tri nho thu hai trong mang
                if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
                int mangMin[100];
                int dem = 0;
                int bienNho;
                int demMin;
                for(int i = 0; i < soPhanTu; i++){
                    mang[i] = mangMin[dem];
                    dem++;
                }
                //bat dau xet mangMin va xoa phan tu be nhat
                int min_idx = 0;
                for(demMin = 0; demMin < dem; demMin++){
                    if(mangMin[min_idx] > mangMin[demMin]){
                        bienNho = mangMin[min_idx];
                        mangMin[min_idx] = mangMin[demMin];
                        mangMin[demMin] = bienNho;
                    }
                }
                for(int i = demMin; i < dem; i++){
                    mangMin[i] = mangMin[i + 1];
                    dem--;
                }
                //tim phan tu be thu 2
                min_idx = 0;
                for(demMin = 0; demMin < dem; demMin++){
                    if(mangMin[min_idx] > mangMin[demMin]){
                        bienNho = mangMin[min_idx];
                        mangMin[min_idx] = mangMin[demMin];
                        mangMin[demMin] = bienNho;
                    }
                }
                printf("phan tu be thu hai la: %d", mangMin[min_idx]);
                break;*/
            
            case 5: //Them mot phan tu vao trong mang
                if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
                int i;
                int viTriThem, gtriThem;
                printf("vi tri muon them trong mang: ");
                scanf("%d", &viTriThem);
                if(viTriThem < 0 || viTriThem > soPhanTu){
                    printf("vi tri them khong hop le");
                    break;
                }
                printf("gia tri them vao trong mang: ");
                scanf("%d", &gtriThem);
                for(int i = soPhanTu; i >= 0; i--){
                    mang[i + 1] = mang[i];
                }
                soPhanTu++;
                mang[i + 1] = gtriThem;
                printf("da them phan tu vao trong mang");
                break;
            
            case 6: //Xoa phan tu trong mang
                if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
                int viTriXoa;
                printf("nhap vi tri xoa cua mang");
                scanf("%d", &viTriXoa);
                if(viTriXoa < 0 || viTriXoa >= soPhanTu){
                    printf("vi tri xoa khong hop le");
                    break;
                }
                for(int i = viTriXoa; i < soPhanTu; i++){
                    mang[i] = mang[i + 1];
                }
                soPhanTu--;
                printf("da xoa phan tu trong mang");

            case 7: //Sap xep mang theo thu tu giam dan (Insertion sort)
                if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
                checkSapXep = 1;
                for(int i = 1; i < soPhanTu; i++){
                    int key = mang[i];
                    int j = i - 1;
                    for(j; j >= 0 && key > mang[j]; j--){
                        mang[j + 1] = mang[j];
                    }
                    mang[j + 1] = key;
                }
                printf("da sap xep");
                break;
            
          /*  case 8: //Tim phan tu co trong mang
                if(check == 0){
                    printf("chua nhap mang");
                    break;
                }
                if(checkSapXep == 0){
                    printf("chua sap xep");
                    break;
                }
                int mid;
                int start = 0;
                int end = sizeof(mang)/sizeof(mang[0]);*/
            case 11: // thoat
                return 0;
            default:
                printf("nhap sai ky tu vui long nhap lai");
        }   

    }
}