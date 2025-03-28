#include<stdio.h>
#include<conio.h>
void main(){
	int product_id[20],product_price[20],product_quantity[20],bquantity[20],subtotal[20],upquantity[20],price[20];
	int choice,display,i=0,j,k,o,p,a,e,snum,total,sno,num,plimit,qlimit,blimit,ulimit;
	char product_name[20][10],name[10],bname[20][10],pname[20][10],upname[20][10],up,add,conn,badd;
	clrscr();
	do{
		clrscr();
		printf("--------------------------------------------------------------------------------\n");
		printf("\t\t\t\t X-MART \n");
		printf("--------------------------------------------------------------------------------\n");
		printf("\t\t\t\t 1.Add Item \n\n");
		printf("\t\t\t\t 2.All Product Details \n\n");
		printf("\t\t\t\t 3.Single Product Details \n\n");
		printf("\t\t\t\t 4.Update Product Details \n\n");
		printf("\t\t\t\t 5.Billing Section \n\n");
		printf("\t\t\t\t 6.Exit \n\n");
		printf("--------------------------------------------------------------------------------");
		printf("\nEnter Your Choice:");
		scanf("%d",&choice);
		printf("--------------------------------------------------------------------------------\n");
		switch(choice){
			case 1:
				do{
					clrscr();
					printf("--------------------------------------------------------------------------------\n");
					printf("\t\t\t\t ADD ITEM \n\n");
					printf("--------------------------------------------------------------------------------\n");
					printf("Enter the Product Name:");
					scanf("%s",&product_name[i]);
					plimit=1;
					while(plimit<=3){
						printf("Enter the Product Price:");
						scanf("%d",&product_price[i]);
						if(product_price[i]>0){
							qlimit=1;
							while(qlimit<=3){
								printf("Enter the Product Quantity:");
								scanf("%d",&product_quantity[i]);
								if(product_quantity[i]>0){
									printf("--------------------------------------------------------------------------------\n");
									printf("Item Added Successfully\n");
									printf("--------------------------------------------------------------------------------\n");
									printf("Add More Item:(y/n):");
									fflush(stdin);
									scanf("%s",&add);
									i++;
									break;
								}else{
									printf("\nDo Not Accept Negative Values and Zero\n");
									printf("--------------------------------------------------------------------------------\n");
								}
								qlimit++;
							}
							if(qlimit==4){
								printf("Your Maximum of Attempt is Over\n");
							}
							break;
						}else{
							printf("\nDo Not Accept Negative Values and Zero\n");
							printf("--------------------------------------------------------------------------------\n");
						}
						plimit++;
					}
					if(plimit==4){
						printf("Your Maximum of Attempt is Over\n");
					}
				}while(add=='y');
				break;
			case 2:
				clrscr();
				snum=1;
				if(i>=1){
					printf("--------------------------------------------------------------------------------\n");
					printf("\t\t\t\t PRODUCT DETAILS \n\n");
					printf("--------------------------------------------------------------------------------\n");
					printf("S.No\tProduct_Name\tProduct_Price\tProduct_Quantity\n");
					printf("--------------------------------------------------------------------------------\n");
					display=0;
					while(display<i){
						printf(" %d \t\t %s \t\t %d \t\t %d\n",snum,product_name[display],product_price[display],product_quantity[display]);
						display++;
						snum++;
					}
				}else{
					printf("\nNo Products Available\n");
				}
				break;
			case 3:
				clrscr();
				if(i>=1){
					printf("--------------------------------------------------------------------------------\n");
					printf("\t\t\t\t Single Product Details \n\n");
					printf("--------------------------------------------------------------------------------\n");
					printf("Enter the Product Name:");
					scanf("%s",&name);
					j=0;
					num=1;
					while(j<i){
						if((strcmp(name,product_name[j]))==0){
							printf("--------------------------------------------------------------------------------\n");
							printf("S.No\tProduct_Name\tProduct_Price\tProduct_Quantity\n");
							printf("--------------------------------------------------------------------------------\n");
							printf("%d \t\t %s \t\t %d \t\t %d\n",num,product_name[j],product_price[j],product_quantity[j]);
							break;
						}
						j++;
						num++;
					}
					if(i==j){
						printf("\nThis Product was Not Available\n");
					}
				}else{
					printf("\nNo Products Available\n");
				}
				break;
			case 4:
				clrscr();
				printf("--------------------------------------------------------------------------------\n");
				printf("\t\t\t\t UPDATE PRODUCT DETAILS \n\n");
				printf("--------------------------------------------------------------------------------\n");
				p=0;
				do{
					o=0;
					printf("Enter the Product Name:");
					scanf("%s",&bname[p]);
						while(o<i){
							if((strcmp(bname[p],product_name[o]))==0){
								printf("Available Quantity of '%s' is: %d\n",product_name[o],product_quantity[o]);
								ulimit=1;
								while(ulimit<=3){
									printf("Enter the Product Quantity:");
									scanf("%d",&upquantity[p]);
									if(upquantity[p]>0){
										printf("--------------------------------------------------------------------------------\n");
										printf("Product Updated Successfully\n");
										printf("--------------------------------------------------------------------------------\n");
										product_quantity[o]=product_quantity[o]+upquantity[p];
										printf("Updated Quantity of '%s' is: %d\n",product_name[o],product_quantity[o]);
										printf("\nDo you want to update more products(y/n):");
										fflush(stdin);
										scanf("%s",&up);
										printf("\n--------------------------------------------------------------------------------\n");
										p++;
										break;
									}else{
										printf("\nDo Not Accept Negative Values and Zero\n");
										printf("--------------------------------------------------------------------------------\n");
									}
									ulimit++;
								}
								if(ulimit==4){
									printf("Your Maximum of Attempt is Over\n");
								}
								break;
							}
							o++;
						}
						if(o==i){
							printf("This Product was Not Available\n");
							break;
						}
				}while(up=='y');
				break;
			case 5:
				clrscr();
				if(i>=1){
					printf("--------------------------------------------------------------------------------\n");
					printf("\t\t\t\t BILLING SECTION \n\n");
					printf("--------------------------------------------------------------------------------\n");
					printf("\n");
					total=0;
					a=0;
					do{
						k=0;
						printf("Enter the Product Name:");
						scanf("%s",&bname[a]);
							while(k<i){
								if((strcmp(bname[a],product_name[k]))==0){
									blimit=1;
									while(blimit<=3){
										printf("Enter the Product Quantity:");
										scanf("%d",&bquantity[a]);
										if(product_quantity[k]>=bquantity[a]){
											if(bquantity[a]>0){
												printf("--------------------------------------------------------------------------------\n");
												printf("Buy more Products:(y/n):");
												scanf("%s",&badd);
												printf("--------------------------------------------------------------------------------\n");
												price[a]=product_price[k];
												subtotal[a]=product_price[k]*bquantity[a];
												total=subtotal[a]+total;
												product_quantity[k]=product_quantity[k]-bquantity[a];
												strcpy(pname[a],product_name[k]);
												a++;
												break;
											}else{
												printf("\nDo Not Accept Negative Values and Zero\n");
												printf("--------------------------------------------------------------------------------\n");
											}
										}else{
											printf("Invalid Quantity\n");
											printf("--------------------------------------------------------------------------------\n");
										}
										blimit++;
									}
									if(blimit==4){
										printf("Your Maximum of Attempt is Over\n");

									}
									break;
								}
								k++;
							}
							if(k==i){
								printf("This Product was Not Available\n");
								break;
							}
					}while(badd=='y');
					if(a>=1){
						clrscr();
						sno=1;
						e=0;
						printf("--------------------------------------------------------------------------------\n");
						printf(" S.No\tProduct_Name\tQuantity\tPrice\tTotal\n");
						printf("--------------------------------------------------------------------------------\n");
						while(sno<=a){
							printf("%d \t %s \t\t %d \t\t %d \t %d\n",sno,pname[e],bquantity[e],price[e],subtotal[e]);
							e++;
							sno++;
						}
						printf("--------------------------------------------------------------------------------\n");
						printf(" \t\t\t\t   Total Amount: %d\n",total);
						printf("--------------------------------------------------------------------------------\n");
					}
				}else{
					printf("No Products Available\n");
				}
				break;
			case 6:
				exit(0);
			default:
				clrscr();
				printf("\nInvalid Choice\n");
				break;
		}
		printf("--------------------------------------------------------------------------------");
		   printf("\nGo Back to Main Menu:(y/n):");
		   scanf("%s",&conn);
	}while(conn=='y');
	getch();

}