
 #include <iostream>
 #include <cmath>
 #include <cstdio>
 #include <cstring>
 #include <climits>
 #include <vector>
 #include <cassert>
 #include <string>
 #include <algorithm>
 #include <stack>
 #include <set>
 #include <queue>
 
 using namespace std;
 
 struct Position{
	     int r, c;
	 
		     Position()
		     {
		     }
	 
		     Position(int r, int c)
		     {
		         this->r = r;
		         this->c = c;
		     }
	 
		     Position(const Position& other) :r(other.r), c(other.c){
		 
			 
	}
	 
		     Position& operator =(const Position& other){
		         r = other.r;
		         c = other.c;
		         return *this;
		 
	}
	  };
 
 const int MAXR = 26;
 const int MAXC = 30;
 const int MAXN = MAXR * MAXC;
 
 int dis[MAXR][MAXC][MAXR][MAXC];
 
 const int directx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
 const int directy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
 
 bool marked[MAXR][MAXC];
 int index(int r, int c, int C)
 {
	     return r * C + c;
	 }
 
 bool isWithin(int r, int c, int R, int C)
 {
	     return r >= 0 && r < R && c >= 0 && c < C;
	 }
 
 void spfa(const Position &s, const int R, const int C)
 {
	     if (marked[s.r][s.c])
		     {
		         return;
		     }
	     marked[s.r][s.c] = true;
	     for (int i = 0; i < R; ++i)
		     {
		         for (int j = 0; j < C; ++j)
			         {
			             dis[s.r][s.c][i][j] = INT_MAX;
			         }
		     }
	     dis[s.r][s.c][s.r][s.c] = 0;
	 
		     deque<Position> que;
	     bool onQueue[MAXR][MAXC];
	     memset(onQueue, false, MAXN * sizeof(bool));
	 
		     //int s = index(r, c, C);  
		     que.push_back(s);
	     onQueue[s.r][s.c] = true;
	 
		     while (!que.empty())
		     {
		         /*
				            if(que.size() == 51 && que.front().r == 24 && que.front().c == 18)
				            {
				            fprintf(stdout, "debug\n");
				            }
				            fprintf(stdout, "que.size: %d\n", que.size());
				            */
				            Position u = que.front();
		         que.pop_front();
		         //fprintf(stdout, "u: (%d, %d)\n", u.r, u.c);  
			         if (dis[s.r][s.c][u.r][u.c] == INT_MAX)
			         {
			             continue;
			         }
		         onQueue[u.r][u.c] = false;
		         for (int d = 0; d < 8; ++d)
			         {
			             int vr = u.r + directx[d];
			             int vc = u.c + directy[d];
			             if (!isWithin(vr, vc, R, C))
				             {
				                 continue;
				             }
			 
				             Position v(vr, vc);
			             //v.r = vr;  
				             //v.c = vc;  
				             if (dis[s.r][s.c][u.r][u.c] + 1 < dis[s.r][s.c][v.r][v.c])
				             {
				                 dis[s.r][s.c][v.r][v.c] = dis[s.r][s.c][u.r][u.c] + 1;
				                 if (!onQueue[v.r][v.c])
					                 {
					                     if (que.empty() ||
						                         dis[s.r][s.c][v.r][v.c] < dis[s.r][s.c][que.front().r][que.front().c])
						                     {
						                         que.push_front(v);
						                     }
					                     else
						                     {
						                         que.push_back(v);
						                     }
					                     onQueue[v.r][v.c] = true;
					                 }
				             }
			         }
		     }
	 }
 
 
 int main()
 {
	     FILE *fin = fopen("camelot.in", "r");
	     FILE *fout = fopen("camelot.out", "w");
	     //freopen("log.txt", "w", stdout);  
		 
		     int R, C;
	     fscanf(fin, "%d%d\n", &C, &R);
	     //int N = R * C;  
		 
		     memset(marked, false, R * C * sizeof(bool));
	 
		     Position king;
	     char r;
	     fscanf(fin, "%c", &r);
	     king.r = r - 'A';
	     int c;
	     fscanf(fin, "%d\n", &c);
	     king.c = c - 1;
	     assert(king.r < R && king.c < C);
	     //fprintf(stdout, "king: \n%d %d\n", king.r, king.c);  
		     vector<Position> knights;
	     while (fscanf(fin, "%c", &r) > 0)
		     {
		         if (r < 'A' || r > 'Z')
			         {
			             continue;
			         }
		         Position knight;
		         knight.r = r - 'A';
		         fscanf(fin, " %d", &c);
		         knight.c = c - 1;
		         knights.push_back(knight);
		     }
	 
		     //for(int i = 0; i < knights.size(); ++i)  
		     //{  
		     //assert(knights[i].r < R && knights[i].c < C);  
		     //fprintf(stdout, "%c %d\n", knights[i].r + 'A', knights[i].c + 1);  
		     //}  
		     //fprintf(stdout, "number of knights: %d\n", knights.size());  
		 
		     for (int i = 0; i < knights.size(); ++i)
		     {
		         spfa(knights[i], R, C);
		         /*
					         for(int r = 0; r < R; ++r)
					         {
					         for(int c = 0; c < C; ++c)
					         {
					         fprintf(stdout, "%d\t", dis[knights[i].r][knights[i].c][r][c]);
					         }
					         fprintf(stdout, "\n");
					         }
					         */
					     }
	 
		     int minmoves = -1;
	     for (int gr = 0; gr < R; ++gr)//gathering point  
		     {
		         for (int gc = 0; gc < C; ++gc)
			         {
			             int knightsdis = 0;
			             for (int i = 0; i < knights.size(); ++i)
				             {
				                 knightsdis += dis[knights[i].r][knights[i].c][gr][gc];
				             }
			             int kingmove = 0;
			             int pr, pc;
			             int knightsmove = 0;
			             for (int kingmover = -2; kingmover <= 2; ++kingmover)
				             {
				                 for (int kingmovec = -2; kingmovec <= 2; ++kingmovec)
					                 {
					                     kingmove = max(abs(kingmover), abs(kingmovec));
					                     //if(!kingmover && !kingmovec)  
						                     //{  
						                         //kingmove = 0;  
						                     //}  
						                     //else  
						                     //{  
						                         //kingmove = 1;  
						                     //}  
						                     pr = king.r + kingmover;
					                     pc = king.c + kingmovec;
					                     if (!isWithin(pr, pc, R, C))
						                     {
						                         continue;
						                     }
					                     spfa(Position(pr, pc), R, C);
					                     for (int pk = 0; pk < knights.size(); ++pk) //pickup knight  
						                     {
						                         if (dis[knights[pk].r][knights[pk].c][pr][pc] == INT_MAX
							  || dis[pr][pc][gr][gc] == INT_MAX)
							                         {
							                             continue;
							                         }
						                         knightsmove = knightsdis - dis[knights[pk].r][knights[pk].c][gr][gc] + dis[knights[pk].r][knights[pk].c][pr][pc] + dis[pr][pc][gr][gc];
						                         int moves = knightsmove + kingmove;
												 
						                         if (minmoves < 0 || moves < minmoves)
							                         {
							                             minmoves = moves;
														 cout << knightsmove << "  " << kingmove << endl;
							                         }
						                     }
					                 }
				             }
			         }
		     }
	     fprintf(fout, "%d\n", minmoves < 0 ? 0 : minmoves);
	     return 0;
	 }
