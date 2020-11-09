#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 10
#define K1 2
#define K2 3

struct dentro{
	int gcubes, rcubes;
	int value;
	struct dentro *child1;
	struct dentro *child2;
	struct dentro *child3;
	struct dentro *move;
};

int construct_tree(int p, int col,struct dentro *tree){
	struct dentro *d1,*d2,*d3;
	int a,a1,a2,b,b1,b2,c,c1,c2;

	if (tree->rcubes==0 &tree->gcubes==0 & p==1){
		tree->value=-1000;
		return tree->value;
	}else if (tree->rcubes==0 &tree->gcubes==0 & p==0){
		tree->value=1000;
		return tree->value;
	}else if(p==1 & col==0){
		d1=(struct dentro *)malloc(sizeof(struct dentro));
		d1->rcubes=tree->rcubes-1;
		tree->child1=d1;
		a1=construct_tree(0,0,d1);
		a2=construct_tree(0,1,d1);
		if(a1>=a2)
			a=a1;
		else
			a=a2;
		tree->value=a;
		tree->move=d1;
		if((tree->rcubes-K1)>=0){
			d2=(struct dentro *)malloc(sizeof(struct dentro));
			d2->rcubes=tree->rcubes-K1;
			tree->child2=d2;
			b1=construct_tree(0,0,d2);
			b2=construct_tree(0,1,d2);
			if(b1>=b2)
				b=b1;
			else
				b=b2;
			tree->value=b;
			tree->move=d2;
		}
		if((tree->rcubes-K2)>=0){
			d3=(struct dentro *)malloc(sizeof(struct dentro));
			d3->rcubes=tree->rcubes-K2;
			tree->child3=d3;
			c1=construct_tree(0,0,d3);
			c2=construct_tree(0,1,d3);
			if(c1>=c2)
				c=c1;
			else
				c=c2;
			tree->value=c;
			tree->move=d3;
		}
		return tree->value;
	}else if(p==1 & col==1){
		d1=(struct dentro *)malloc(sizeof(struct dentro));
		d1->gcubes=tree->gcubes-1;
		tree->child1=d1;
		a1=construct_tree(0,0,d1);
		a2=construct_tree(0,1,d1);
		if(a1>=a2)
			a=a1;
		else
			a=a2;
		tree->value=a;
		tree->move=d1;
		if((tree->gcubes-K1)>=0){
			d2=(struct dentro *)malloc(sizeof(struct dentro));
			d2->gcubes=tree->gcubes-K1;
			tree->child2=d2;
			b1=construct_tree(0,0,d2);
			b2=construct_tree(0,1,d2);
			if(b1>=b2)
				b=b1;
			else
				b=b2;
			tree->value=b;
			tree->move=d2;
		}
		if((tree->gcubes-K2)>=0){
			d3=(struct dentro *)malloc(sizeof(struct dentro));
			d3->gcubes=tree->gcubes-K2;
			tree->child3=d3;
			c1=construct_tree(0,0,d3);
			c2=construct_tree(0,1,d3);
			if(c1>=c2)
				c=c1;
			else
				c=c2;
			tree->value=c;
			tree->move=d3;
		}
		return tree->value;
	}else if(col==0){
				d1=(struct dentro *)malloc(sizeof(struct dentro));
		d1->rcubes=tree->rcubes-1;
		tree->child1=d1;
		a1=construct_tree(0,0,d1);
		a2=construct_tree(0,1,d1);
		if(a1>=a2)
			a=a1;
		else
			a=a2;
		tree->value=a;
		tree->move=d1;
		if((tree->rcubes-K1)>=0){
			d2=(struct dentro *)malloc(sizeof(struct dentro));
			d2->rcubes=tree->rcubes-K1;
			tree->child2=d2;
			b1=construct_tree(0,0,d2);
			b2=construct_tree(0,1,d2);
			if(b1>=b2)
				b=b1;
			else
				b=b2;
			tree->value=b;
			tree->move=d2;
		}
		if((tree->rcubes-K2)>=0){
			d3=(struct dentro *)malloc(sizeof(struct dentro));
			d3->rcubes=tree->rcubes-K2;
			tree->child3=d3;
			c1=construct_tree(0,0,d3);
			c2=construct_tree(0,1,d3);
			if(c1>=c2)
				c=c1;
			else
				c=c2;
			tree->value=c;
			tree->move=d3;
		}
		return tree->value;
	}else if(col==1){
		d1=(struct dentro *)malloc(sizeof(struct dentro));
		d1->gcubes=tree->gcubes-1;
		tree->child1=d1;
		a1=construct_tree(0,0,d1);
		a2=construct_tree(0,1,d1);
		if(a1>=a2)
			a=a1;
		else
			a=a2;
		tree->value=a;
		tree->move=d1;
		if((tree->gcubes-K1)>=0){
			d2=(struct dentro *)malloc(sizeof(struct dentro));
			d2->gcubes=tree->gcubes-K1;
			tree->child2=d2;
			b1=construct_tree(0,0,d2);
			b2=construct_tree(0,1,d2);
			if(b1>=b2)
				b=b1;
			else
				b=b2;
			tree->value=b;
			tree->move=d2;
		}
		if((tree->gcubes-K2)>=0){
			d3=(struct dentro *)malloc(sizeof(struct dentro));
			d3->gcubes=tree->gcubes-K2;
			tree->child3=d3;
			c1=construct_tree(0,0,d3);
			c2=construct_tree(0,1,d3);
			if(c1>=c2)
				c=c1;
			else
				c=c2;
			tree->value=c;
			tree->move=d3;
		}
		return tree->value;
	}
}


int main() {
	int c,p,color;
	struct dentro *tree=(struct dentro *)malloc(sizeof(struct dentro));
	printf("Number of cubes:\nRed: %d\nGreen: %d\n",M,M);
	p=1;
	tree->rcubes=M;
	tree->gcubes=M;
	construct_tree(1,0,tree);
	while(1){
		if (tree->rcubes==0 & tree->gcubes==0 & p==1){
			printf("WINNER: MIN!!!\n");
			break;
		}else if (tree->rcubes==0 & tree->gcubes==0 & p==0){
			printf("WINNER: MAX!!!\n");
			break;
		}else if(p==1){
			tree=tree->move;
			printf("MAX played. Number of cubes:\n Red: %d\n Green: %d\n",tree->rcubes, tree->gcubes);
			p=0;
		}else{
			printf("How many cubes and what color you want to remove? 1, %d or %d\n. Press 0 for red 1 for green", K1, K2);
			scanf("%d %d", &c, &color);
			if(color==0){
				if(c==K1 && (tree->rcubes-K1)<0)
					printf("Invalid move!");
				if(c==K2 && (tree->rcubes-K2)<0)
					printf("Invalid move!");
				else if(c==1){
					tree=tree->child1;
					printf("MIN played. Number of cubes:\n Red: %d\n Green: %d\n",tree->rcubes, tree->gcubes);
					p=1;
				}else if(c==K1){
					tree=tree->child2;
					printf("MIN played. Number of cubes:\n Red: %d\n Green: %d\n",tree->rcubes, tree->gcubes);
					p=1;
				}else if(c==K2){
					tree=tree->child3;
					printf("MIN played. Number of cubes:\n Red: %d\n Green: %d\n",tree->rcubes, tree->gcubes);
					p=1;
				}
			}else if(color==1){
				if(c==K1 && (tree->gcubes-K1)<0)
					printf("Invalid move!");
				if(c==K2 && (tree->gcubes-K2)<0)
					printf("Invalid move!");
				else if(c==1){
					tree=tree->child1;
					printf("MIN played. Number of cubes:\n Red: %d\n Green: %d\n",tree->rcubes, tree->gcubes);
					p=1;
				}else if(c==K1){
					tree=tree->child2;
					printf("MIN played. Number of cubes:\n Red: %d\n Green: %d\n",tree->rcubes, tree->gcubes);
					p=1;
				}else if(c==K2){
					tree=tree->child3;
					printf("MIN played. Number of cubes:\n Red: %d\n Green: %d\n",tree->rcubes, tree->gcubes);
					p=1;
				}
			}
		}	
	}
	return 0;
}
