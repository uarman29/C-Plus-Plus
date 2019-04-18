/*
 * CSc103 Project 3: Game of Life
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:www.cplusplus.com *https://stackoverflow.com/questions/7682455/removing-empty-elements-from-a-vector-of-strings
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 8-10
 */

#include <cstdio>
#include <stdlib.h> // for exit();
#include <getopt.h> // to parse long arguments.
#include <unistd.h> // sleep
#include <vector>
#include<iostream>
using std::vector;
#include <string>
using std::string;
using namespace std;

static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Text-based version of Conway's game of life.\n\n"
"   --seed,-s     FILE     read start state from FILE.\n"
"   --world,-w    FILE     store current world in FILE.\n"
"   --fast-fw,-f  NUM      evolve system for NUM generations and quit.\n"
"   --help,-h              show this message and exit.\n";

size_t max_gen = 0; /* if > 0, fast forward to this generation. */
string wfilename =  "/tmp/gol-world-current"; /* write state here "/tmp/gol-world-current"*/
FILE* fworld = 0; /* handle to file wfilename. */
string initfilename = "/tmp/gol-world-current"; /* read initial state from here. */
vector<vector<bool> > grid;
/* see the hints section of the readme: to get the basics working,
 * uncomment this next line, and you'll have a suitable test vector
 * to which you can apply the rules. */
// #define WARMUP 1

#ifdef WARMUP
vector<vector<bool> > world = {
#include "res/bglider-small"
};
#endif

/* NOTE: you don't have to write these functions -- this is just how
 * I chose to organize my code. */
void printGrid()
{
	for(int j=0;j<grid.size();j++)
	{
		for(int i=0;i<grid[j].size();i++)
		{
			if(grid[j][i])
			{
				cout<<"O";
			}
			else
			{
				cout<<".";
			}
		}
			cout<<"\n";
	}
}
int initFromFile(const string& fname)
{
	FILE* f = fopen(fname.c_str(),"rb");
	if(fname=="-")
	{
		f=stdin;
	}
	if(!f){exit(1);}
	grid.push_back(vector<bool>());
	int rows = 0;
	char current;
	while(fread(&current,1,1,f))
	{
		if(current=='\n')
		{
			rows++;
			grid.push_back(vector<bool>());
		}
		else if(current=='.')
		{
			grid[rows].push_back(false);
		}
		else
		{
			grid[rows].push_back(true);
		}
	}
	for(int i=0;i<grid.size();i++)
	{
		if(grid[i].size()==0)
		{
			grid.erase(grid.begin()+i);
		}
	}
	fclose(f);
	return 0;
}/* read initial state into vectors. */

int nbrCount(size_t currentRow, size_t currentColumn)
{
	int neighborCount = 0;
	int rows = grid.size()-1;
	int columns = grid[0].size()-1;
	int nextColumn= currentColumn+1;
	int nextRow= currentRow+1;
	int previousColumn = currentColumn-1;
	int previousRow = currentRow-1;
	vector<bool> neighbors;

	if(currentColumn == columns)
	{
		nextColumn = 0;
	}
	else
	{
		if(currentColumn==0)
		{
			previousColumn = columns;
		}
	}
	if(currentRow == rows)
	{
		nextRow = 0;
	}
	else
	{
		if(currentRow==0)
		{
			previousRow = rows;
		}
	}
	neighbors.push_back(grid[previousRow][previousColumn]);
	neighbors.push_back(grid[previousRow][currentColumn]);
	neighbors.push_back(grid[previousRow][nextColumn]);
	neighbors.push_back(grid[currentRow][previousColumn]);
	neighbors.push_back(grid[currentRow][nextColumn]);
	neighbors.push_back(grid[nextRow][previousColumn]);
	neighbors.push_back(grid[nextRow][currentColumn]);
	neighbors.push_back(grid[nextRow][nextColumn]);

	for(int i=0;i<neighbors.size();i++)
	{
		if(neighbors[i])
		{
			neighborCount++;
		}
	}
	return neighborCount;

}

void dumpState(const string& fname)
{
	FILE* f = fopen(fname.c_str(),"wb");
	if(fname=="-")
	{
		f=stdout;
	}
	int rows = grid.size();
	char nl = '\n';
	for(int j=0;j<rows;j++)
	{
		//if(j!=0){fprintf(f,"\n");}
		for(int i=0;i<grid[j].size();i++)
		{
			if(grid[j][i])
			{
				fwrite("O",1,1,f);
			}
			else
			{
				fwrite(".",1,1,f);
			}
		}
		fwrite(&nl,1,1,f);
		//fprintf(f,"\n");
	}
	fclose(f);
}

void update()
{
	vector<vector<bool> > temp;
	temp=grid;
	int rows = grid.size();
	int neighbors;
	for(int j=0;j<rows;j++)
	{
		for(int i=0;i<grid[j].size();i++)
		{
			neighbors = nbrCount(j,i);
			if(neighbors<2||neighbors>3)
			{
				temp[j][i]=false;
			}
			else if(neighbors==3)
			{
				temp[j][i]=true;
			}
		}
	}
	grid=temp;
}


void mainLoop()
{
	/* TODO: write this */
	/* update, write, sleep */
	if (max_gen == 0)
	{
		while(true)
		{
			update();
			dumpState(wfilename);
			sleep(1);
		}
		/* make one generation update per second */
	}
	else
	{
		while(max_gen>0)
		{
			update();
			max_gen--;
		}
		dumpState(wfilename);
		/* go through generations as fast as you can until
		 * max_gen is reached... */
	}
}
/* NOTE: you can use a *boolean* as an index into the following array
 * to translate from bool to the right characters: */
char text[3] = ".O";

int main(int argc, char *argv[]) {
	// define long options
	static struct option long_opts[] = {
		{"seed",    required_argument, 0, 's'},
		{"world",   required_argument, 0, 'w'},
		{"fast-fw", required_argument, 0, 'f'},
		{"help",    no_argument,       0, 'h'},
		{0,0,0,0}
	};
	// process options:
	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "hs:w:f:", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case 's':
				initfilename = optarg;
				break;
			case 'w':
				wfilename = optarg;
				break;
			case 'f':
				max_gen = atoi(optarg);
				break;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}
	}

	/* NOTE: at this point wfilename initfilename and max_gen
	 * are all set according to the command line. */
	/* If you wrote the initFromFile function, call it here: */
	initFromFile(initfilename);
	mainLoop();
	return 0;
}
