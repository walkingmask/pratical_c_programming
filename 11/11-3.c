
/*---
 * - 11-3.c
 * 2015/2/10(TUE)
 * Walking Mask
 *
 * - プログラムの説明
 * C言語勉強会2014lt用プログラム
 * テキストC実践プログラミング 実習11-3
 * 黒い背景に白い線を引くように例11-3を変更
---*/

#include <stdio.h>

#define X_SIZE 40
#define Y_SIZE 60

char graphics[X_SIZE/8][Y_SIZE];

/* マクロ */
#define SET_BIT(x, y) graphics[(x)/8][y] |= (0x80 >> ((x)%8))

/* 関数 */
void print_graphics(void);

int main(void){
	int loc;

	for(loc=X_SIZE-1; loc>0; --loc)		// 逆対角線を描くためにセットするビットを調整
		SET_BIT((X_SIZE-1)-loc, loc);

	print_graphics();
	return(0);
}

void print_graphics(void){
	int x, y;
	unsigned int bit;
	for(y=0; y<Y_SIZE; ++y){
		for(x=0; x<X_SIZE/8; ++x){
			for(bit=0x80; bit>0; bit=(bit>>1)){
				if((graphics[x][y] & bit) != 0)
					printf("/");	// スラッシュで線を表現
				else
					printf(" ");
			}
		}
		printf("\n");
	}
}

/*---
出力結果
% ./11-3
                                        
                                      / 
                                     /  
                                    /   
                                   /    
                                  /     
                                 /      
                                /       
                               /        
                              /         
                             /          
                            /           
                           /            
                          /             
                         /              
                        /               
                       /                
                      /                 
                     /                  
                    /                   
                   /                    
                  /                     
                 /                      
                /                       
               /                        
              /                         
             /                          
            /                           
           /                            
          /                             
         /                              
        /                               
       /                                
      /                                 
     /                                  
    /                                   
   /                                    
  /                                     
 /                                      
/                                       
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        

---*/
