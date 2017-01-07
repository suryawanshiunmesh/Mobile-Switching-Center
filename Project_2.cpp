// -----------------------------------------
// CS 6596 - Project 2
// Name: Unmesh Suryawanshi
// Net id: qd6395
// -----------------------------------------

// Declaration of the header files
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include<fstream>

using namespace std;
#define first_call 1
#define end_call 2

// Declaration of structure
template<class d_type> class elt
{
	public:
		d_type val;
		elt<d_type> *forward;
	};

template<class d_type> class seq
{
	public:
		elt<d_type> *first;
   		seq()
    		{
			first = NULL;
			}

	//login to calculate the length of the list
    	int l_len()
    	{
        	elt<d_type> *node=first;
        	int t_elt=0;
        	while(node!=NULL)
        	{
            		node = node->forward;
            		t_elt++;
        		}
        	return t_elt;
    		}

	// logic to check the black data in LL
	bool check_empty()
    	{
		return(first == NULL);
		}

	// add the data in LL
   	void add_data(d_type tmp1)
    	{
        	elt<d_type> *tmp = new elt<d_type>;
        	tmp->val = tmp1;
        	tmp->forward = NULL;
        	if(first == NULL)
        	{
            		first = tmp;
        		}
        	else
        	{
            		elt<d_type> *node=first;
            		while(node->forward!=NULL)
            		{
                		node = node->forward;
            			}
            		node->forward = tmp;
        		}
    		}

    // to initiate with the 1st val
	d_type& find_first_val()
    	{
		return first->val;
		}

    	d_type& find_val_at_index(int idx)
    	{
        	elt<d_type> *node=first;
        	for(int i=0; i<idx; i++)
        	{
            		if(node == NULL)
                		return first->val;
            		node = node->forward;
        		}
        	return node->val;
    		}

        void del(d_type &tmp1)
    	{
        	elt<d_type> *node=first;
        	if(first->val == tmp1)
        	{
            		first = NULL;
        		}

		while(node->forward!=NULL)
        	{
            		if(node->forward->val == tmp1)
            		{
                		node->forward = node->forward->forward;
            			}
            		node = node->forward;
        		}
    		}

    	void del_first()
    	{
        	elt<d_type> *first_elt_new;
        	if(first == NULL)
            		return;
        	first_elt_new = first->forward;
        	delete first;
        	first = first_elt_new;
    		}

    	void del()
    	{
        	first = NULL;
    		}

    	d_type& del_end()
    	{
        	elt<d_type> *node=first,*tmp;
        	if(node==NULL)
            		return node->val;
        	if(node->forward == NULL)
        	{
            		first = NULL;
            		return node->val;
        		}
        	while(node->forward->forward != NULL)
        	{
            		node = node->forward;
        		}
        	tmp = node->forward;
        	node->forward = NULL;
        	return tmp->val;
 	   	}
	};

class fixed_data
{
	public:
    		static double cell_r;
    		static int ch_no, pl_exp, cell_no, total_cl, cluster_cell_no, path_mat[9][9];

    		static void set_vals()
    		{
                //Declaration of all the data
        		cell_r = 1000, ch_no = 15, pl_exp = 4, cell_no = 9, total_cl = 3, cluster_cell_no = 3;

	        	path_mat[0][0] = 0;	    path_mat[0][1] = 2000; 	path_mat[0][2] = 2000;  path_mat[0][3] = 4000;
                path_mat[0][4] = 6000; 	path_mat[0][5] = 4000;	path_mat[0][6] = 4000; 	path_mat[0][7] = 6000;  path_mat[0][8] = 6000;
	        	path_mat[1][0] = 2000;	path_mat[1][1] = 0;     path_mat[1][2] = 2000;  path_mat[1][3] = 2000;
        		path_mat[1][4] = 4000;	path_mat[1][5] = 2000;  path_mat[1][6] = 4000;  path_mat[1][7] = 4000;	path_mat[1][8] = 6000;
      	  		path_mat[2][0] = 2000;	path_mat[2][1] = 2000;  path_mat[2][2] = 0;     path_mat[2][3] = 4000;
        		path_mat[2][4] = 4000;	path_mat[2][5] = 2000;  path_mat[2][6] = 2000;  path_mat[2][7] = 4000;  path_mat[2][8] = 4000;
        		path_mat[3][0] = 4000;  path_mat[3][1] = 2000;  path_mat[3][2] = 4000;  path_mat[3][3] = 0;
        		path_mat[3][4] = 2000;	path_mat[3][5] = 2000;  path_mat[3][6] = 4000;	path_mat[3][7] = 4000;  path_mat[3][8] = 6000;
      			path_mat[4][0] = 6000;  path_mat[4][1] = 4000;  path_mat[4][2] = 4000;  path_mat[4][3] = 2000;
     			path_mat[4][4] = 0;     path_mat[4][5] = 2000;  path_mat[4][6] = 4000;  path_mat[4][7] = 2000;  path_mat[4][8] = 4000;
     			path_mat[5][0] = 4000;  path_mat[5][1] = 2000;  path_mat[5][2] = 2000;  path_mat[5][3] = 2000;
       	 		path_mat[5][4] = 2000;  path_mat[5][5] = 0;     path_mat[5][6] = 2000;  path_mat[5][7] = 2000;  path_mat[5][8] = 4000;
     	  		path_mat[6][0] = 4000;  path_mat[6][1] = 4000;  path_mat[6][2] = 2000;  path_mat[6][3] = 4000;
    	   		path_mat[6][4] = 4000;  path_mat[6][5] = 2000;  path_mat[6][6] = 0;     path_mat[6][7] = 2000;  path_mat[6][8] = 2000;
        		path_mat[7][0] = 6000;  path_mat[7][1] = 4000;  path_mat[7][2] = 4000;  path_mat[7][3] = 4000;
    	   		path_mat[7][4] = 2000;  path_mat[7][5] = 2000;  path_mat[7][6] = 2000;  path_mat[7][7] = 0;     path_mat[7][8] = 2000;
    			path_mat[8][0] = 6000;  path_mat[8][1] = 6000;  path_mat[8][2] = 4000;  path_mat[8][3] = 6000;
                path_mat[8][4] = 4000; 	path_mat[8][5] = 4000;  path_mat[8][6] = 2000;   path_mat[8][7] = 2000;  path_mat[8][8] = 0;
	    		}
	};

int fixed_data::ch_no;
int fixed_data::total_cl;
int fixed_data::cell_no;
int fixed_data::cluster_cell_no;
int fixed_data::pl_exp;
double fixed_data::cell_r;
int fixed_data::path_mat[9][9];

// Logic to checking the dropped calls cause due to c0 channel interference.
class track_calls
{
	public:
    		seq<int> interferer;
    		double stored_SIR;
    		int selected_ch;
    		bool current_val;
    		track_calls()
		{
			current_val = false;
			}
	};

//Logic to check cell channel strategy
class cell_ch
{
	public:
    		int chnl_no;
    		bool current_val;
    		int *cl_list;

    		cell_ch(int num)
    		{
        		chnl_no=num;
        		current_val = false;
        		cl_list = new int[9];
        		for(int i=0; i<9; i++)
            			cl_list[i]=0;
    			}

	// Logic to verify - which cell uses all channels
    	bool chck_ch_cluster(int cluster_no)
    	{
        	switch(cluster_no)
        	{
            		case 0:
                	return (cl_list[0]|cl_list[1]|cl_list[2])>0?true:false;

			case 1:
                	return (cl_list[3]|cl_list[4]|cl_list[5])>0?true:false;

			case 2:
                	return (cl_list[6]|cl_list[7]|cl_list[8])>0?true:false;
        		}
        	return false;
    		}
	};

// Logic to check the call details
class call_stored
{
	public:

		double stored_SIR;
		int number, cell, duration, time_req, decision, channel, first_time, end_time;

		seq<track_calls> check_list;

		bool operator==(call_stored &tmp1)
		{
			return (( number!=tmp1.number) || (time_req!=tmp1.time_req) || (first_time!=tmp1.first_time)
	             		||(end_time!=tmp1.end_time)  || (cell!=tmp1.cell) || (duration!=tmp1.duration)
				||(stored_SIR!=tmp1.stored_SIR) ||(decision!=tmp1.decision) || (channel!=tmp1.channel))?false:true;
			}

		// Logic to display all the info. about the call no. start and end time, duration, cell, channel
		void first_op_call();

		void call_end()
		{
			cout<<"Number = "<<number<<" StartTime = "<<first_time<<" EndTime = "<<end_time<<" Cell = "<<(cell+1);
			cout<<" Duration = "<<duration<<" Channel = "<<(channel+1);
			}
	};

class total_call_stored
{
	public:
		seq<call_stored> call_list;

		// Logic to make a arrangement of call events as per the time
		void add_call_stored(call_stored x)
		{
			call_list.add_data(x);
			}

		void add_call_stored_per_time(call_stored x)
		{
			if(call_list.check_empty())
			{
				call_list.add_data(x);
				return;
				}

			elt<call_stored> *up;
			up= call_list.first;
			call_stored call_picker;
			while(up!= NULL)
			{
				call_picker = up->val;
				if(call_picker.time_req > x.time_req)
				{
					elt<call_stored> *tmp = new elt<call_stored>;
					tmp->val = x;
					tmp->forward = up;
					elt<call_stored> *node = call_list.first;
					while(node->forward!= up)
					{
						node = node->forward;
						}
					node->forward = tmp;
					return;
					}
				up= up->forward;
				}
			call_list.add_data(x);
			return;
			}

		void del_call_stored(call_stored x)
		{
			call_list.del(x);
			}

		void del_first_call_stored()
		{
			call_list.del_first();
			}
	};

class dptr
{
public:

    // Declaration of the variables and functions
	static cell_ch **channel_cells;
	static total_call_stored all_calls;
	static int t_calls, t_rj_calls, t_ac_calls;
	static double t_ac_SIR;
	static void starts();
	static void ip_fp(char *path);
	static bool cl_connect(call_stored &e);
	static void operate_stored_call();
	static int hunt_ch(call_stored &e);
	};

cell_ch **dptr::channel_cells;
total_call_stored dptr::all_calls;
int dptr::t_calls;
int dptr::t_rj_calls;
int dptr::t_ac_calls;
double dptr::t_ac_SIR;

void call_stored::first_op_call()
{
	if (stored_SIR >= 22) // condition for the connected call
	{
		// Display the details for the accepted call
		cout<<"Number = "<<number<<"  "<<"Time = "<<first_time<<"  "<<"Cell = "<<cell+1<<"  "<<"Duration = "<<duration<<"  "<<"Accepted"<<"  ""Channel = "<<channel+1<<"  "<<"SIR = "<<stored_SIR<<endl;
		if (check_list.check_empty())
		{
			cout<<"	Interferers: None";
			}
		else
		{
			cout<<"	Interferers: ";
			while(check_list.find_first_val().interferer.l_len()>0)
			{
				int interferer_cell = check_list.find_first_val().interferer.del_end();
				int interferer_path = fixed_data::path_mat[cell][interferer_cell];
				cout<<(interferer_cell+1)<<"/"<<interferer_path<<" ";
				}
			}
		}

	else
	{
		// Display the details of the rejected call
        cout<<"Number = "<<number<<"  "<<"Time = "<<time_req<<"  "<<"Cell = "<<cell+1<<"  "<<"Duration = "<<duration<<"  "<<"Rejected"<<endl;
		cout<<"Reasons:";
		while(check_list.l_len()>0)
		{
			track_calls store_temp = check_list.find_first_val();
			if(store_temp.current_val == true)
			{
				cout<<(store_temp.selected_ch+1)<<"/In Use ";
				}
			else
			{
				cout<<(store_temp.selected_ch+1)<<"/Low SIR = "<<store_temp.stored_SIR<<" dB ";
				}
			check_list.del_first();
			}
		}
	cout<<endl<<endl;
	}

void dptr::starts()
{

    // At start, all values are set to zero
	t_calls = 0, t_rj_calls = 0, t_ac_calls = 0, t_ac_SIR = 0.0;

	channel_cells = new cell_ch*[15];
	for (int i=0; i<fixed_data::ch_no; i++)
	{
		channel_cells[i] = new cell_ch(i);
		}
	}

bool dptr::cl_connect(call_stored &y)
{
	int channel = hunt_ch(y);
	int first_cell = y.cell;
	if(channel >= 0)
	{
		channel_cells[channel]->current_val=true;
		channel_cells[channel]->chnl_no = channel;
		y.channel = channel;
		channel_cells[channel]->cl_list[first_cell]=1;
		return true;
		}
	else
	{
		return false;
		}
	}

void dptr::operate_stored_call()
{
    // Logic to select the next call. Also to look whether we can allocate the channel if its free, if not then drop the call
    while(all_calls.call_list.check_empty() == false)
	{
		call_stored call_picker = all_calls.call_list.find_first_val();
		if (call_picker.decision == first_call) // new call
	        {
			t_calls++;
			cout<<"New Call:";
			if(cl_connect(call_picker))
			{
				t_ac_calls++;
				t_ac_SIR+=call_picker.stored_SIR;
				call_picker.time_req = call_picker.first_time+call_picker.duration;
				call_picker.decision = end_call;
				all_calls.add_call_stored_per_time(call_picker);
				}
			else // rejected call
			{
				t_rj_calls++;
				}
			call_picker.first_op_call();
			}

		else if (call_picker.decision == end_call) // disconnect call
		{
			call_picker.end_time = call_picker.time_req;
			cout<<"Disconnect:";
			call_picker.call_end();
			cout<<endl<<endl;
			channel_cells[call_picker.channel]->current_val=false;
			channel_cells[call_picker.channel]->cl_list[call_picker.cell]=0;
			}

		all_calls.del_first_call_stored();
		}
	}

// Logic for Hunting

// In this fixed channel allocation,
// Channel 1,2,3,4,5 are allocated to cell 1, channel 2,3,4,5,1 are allocated to cell 6, channel 3,4,5,1,2 are allocated to cell 9
// Channel 6,7,8,9,10 are allocated to cell 2, channel 7,8,9,10,6 are allocated to cell 5, channel 8,9,10,6,7 are allocated to cell 8
// Channel 11,12,13,14,15 are allocated to cell 3, channel 12,13,14,15,11 are allocated to cell 4, channel 13,14,15,11,12 are allocated to cell 7

int dptr::hunt_ch(call_stored &y)
{
	int cell_grp[2],*asgn_chs,asgn_ch_no;
	int cluster = (y.cell)/fixed_data::cluster_cell_no;

	switch(y.cell)
	{
// Group 1 contains cell 1,6,9 and they are sharing the same channels 1,2,3,4,5 in a different sequence
		case 0:
            		cell_grp[0] = 5, cell_grp[1] = 8;
            		asgn_ch_no = 5;
            		asgn_chs = new int[5];
            		asgn_chs[0] = 0, asgn_chs[1] = 1, asgn_chs[2] = 2, asgn_chs[3] = 3, asgn_chs[4] = 4;
                    break;

		case 5:
            		cell_grp[0] = 0, cell_grp[1] = 8;
            		asgn_ch_no = 5;
            		asgn_chs = new int[5];
            		asgn_chs[0] = 1, asgn_chs[1] = 2, asgn_chs[2] = 3, asgn_chs[3] = 4, asgn_chs[4] = 0;
            		break;

		case 8:
            		cell_grp[0] = 0, cell_grp[1] = 5;
            		asgn_ch_no = 5;
            		asgn_chs = new int[5];
            		asgn_chs[0] = 2, asgn_chs[1] = 3, asgn_chs[2] = 4, asgn_chs[3] = 0, asgn_chs[4] = 1;
            		break;

// Group 2 contains cell 2,5,8 and they are sharing the same channels 6,7,8,9,10 in a different sequence
        case 1:
            		cell_grp[0] = 4, cell_grp[1] = 7;
            		asgn_ch_no = 5;
            		asgn_chs = new int[5];
            		asgn_chs[0] = 5, asgn_chs[1] = 6, asgn_chs[2] = 7, asgn_chs[3] = 8, asgn_chs[4] = 9;
            		break;

		case 4:
           		cell_grp[0] = 1, cell_grp[1] = 7;
            		asgn_ch_no = 5;
            		asgn_chs = new int[5];
            		asgn_chs[0] = 6, asgn_chs[1] = 7, asgn_chs[2] = 8, asgn_chs[3] = 9, asgn_chs[4] = 5;
            		break;

		case 7:
            		cell_grp[0] = 1, cell_grp[1] = 4;
            		asgn_ch_no = 5;
            		asgn_chs = new int[5];
                    asgn_chs[0] = 7, asgn_chs[1] = 8, asgn_chs[2] = 9, asgn_chs[3] = 5, asgn_chs[4] = 6;
                    break;

// Group 3 contains cell 3,4,7 and they are sharing the same channels 11,12,13,14,15 in a different sequence
        case 2:
                    cell_grp[0] = 3, cell_grp[1] = 6;
            		asgn_ch_no = 5;
            		asgn_chs = new int[5];
            		asgn_chs[0] = 10, asgn_chs[1] = 11, asgn_chs[2] = 12, asgn_chs[3] = 13, asgn_chs[4] = 14;
            		break;
		case 3:
            		cell_grp[0] = 2, cell_grp[1] = 6;
            		asgn_ch_no = 5;
            		asgn_chs = new int[5];
            		asgn_chs[0] = 11, asgn_chs[1] = 12, asgn_chs[2] = 13, asgn_chs[3] = 14, asgn_chs[4] = 11;
                    break;
		case 6:
            		cell_grp[0] = 2, cell_grp[1] = 3;
            		asgn_ch_no = 5;
            		asgn_chs = new int[5];
            		asgn_chs[0] = 12, asgn_chs[1] = 13, asgn_chs[2] = 14, asgn_chs[3] = 10, asgn_chs[4] = 11;
            		break;
			}

		for(int j=0;j<asgn_ch_no;j++)
		{
			int i = asgn_chs[j];
			track_calls store_temp;
			store_temp.selected_ch = i;

			if (dptr::channel_cells[i]->chck_ch_cluster(cluster) == true)
			{
				store_temp.current_val = true;
				y.check_list.add_data(store_temp);
				continue;
			}

		if(dptr::channel_cells[i]->current_val == false)
		{
			y.stored_SIR = 35; // shows that channel is free
			y.check_list.del();
			return i;
			}

		// Logic to find the co channels interference between the same channels which are used different clusters
		for(int k=0; k<2; k++)
		{
			if (dptr::channel_cells[i]->cl_list[cell_grp[k]] == 1)
			{
				store_temp.interferer.add_data(int(cell_grp[k]));
				}
			}

		double SIR, stored_SIR, dnr=0;
		double nmr = pow(fixed_data::cell_r, -fixed_data::pl_exp);
		for (int m=0; m<store_temp.interferer.l_len(); m++)
		{
			int number_cell = store_temp.interferer.find_val_at_index(m);
			int first_cell = y.cell;
			double path = fixed_data::path_mat[first_cell][number_cell];
			dnr += pow(path, -fixed_data::pl_exp);
		}

		SIR = nmr/dnr; // Logic to calculate SIR
		stored_SIR = 10*(log10(SIR));
		store_temp.stored_SIR = stored_SIR;
		if (stored_SIR >= 22) // If this condition satisfies, this channel is alloted
		{
			y.check_list.del();
			y.check_list.add_data(store_temp);
			y.stored_SIR = stored_SIR;
			return i;
			}
		y.check_list.add_data(store_temp); // If value of SIR is low then insert data to the list
		}
	delete[] asgn_chs;
	return -1;
	}

void dptr::ip_fp(char *path)
{
	// Logic to open and close the file
	ifstream fp;
	call_stored newcall_stored;
    	fp.open(path);
    	if(!fp)
    	{
        	cerr<<" File not present..! ";
        	exit(1);
    		}
    	char str[80];
    	fp.getline(str,79);
        while(!fp.eof())
    	{
        	fp>>newcall_stored.number>>newcall_stored.time_req>>newcall_stored.cell>>newcall_stored.duration;
        	newcall_stored.first_time = newcall_stored.time_req;
        	newcall_stored.cell--;
        	newcall_stored.decision = first_call;
        	all_calls.add_call_stored(newcall_stored);
    		}
    	fp.close();
	}

// Declaration of the main function
int main()
{
	double SIR_avg = 0.0, GOS = 0.0;
	fixed_data::set_vals();
	dptr::starts();

	//input file (low and high)
   	dptr::ip_fp("C:/Users/Anonymous/Desktop/Project_2/input-highf16.txt");
    //dptr::ip_fp("C:/Users/Anonymous/Desktop/Project_2/input-lowf16.txt");
	dptr::operate_stored_call();

	// logic to calculate GOS and average SIR
	GOS = ((double)dptr::t_rj_calls/(double)dptr::t_calls)*100.0;
	SIR_avg = (dptr::t_ac_SIR/(double)(dptr::t_ac_calls));

    // Display the final result
    cout<<"-------------------------------------";
    cout<<endl<<"|           Final Result            |";
    cout<<endl<<"-------------------------------------";
    cout<<endl<<" Total Incoming calls : "<<dptr::t_calls<<endl<<" Total Accepted calls : "<<dptr::t_ac_calls<<endl;
    cout<<" Total Rejected calls : "<<dptr::t_rj_calls<<endl<<" GOS                  : "<<GOS<<" % ";
    cout<<endl<<" Average SIR          : "<<SIR_avg<<" dB ";
    cout<<endl<<"-------------------------------------"<<endl;
    return 0;
	}

// End of the program
