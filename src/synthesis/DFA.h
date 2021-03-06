#include "Common.h"

#ifndef DFA_H
#define DFA_H

//update test

using namespace std;

namespace Syft {

  typedef vector<BDD> vbdd;

  class DFA {
  private:
    bool to_upper = true;
    bool remove_first_state = true;
  public:
    DFA(Cudd *m, bool to_upper = true, bool remove_first_state = true);

    virtual ~DFA();

    void initialize(string filename, string partfile);

    void dumpdot(BDD &b, string filename);

    BDD state2bdd(int s);

    int nbits;
    int init;
    int *initbv;
    int nstates;

    int nvars;
    vector<int> finalstates;
    BDD finalstatesBDD;
    vector<BDD> res;
    vector<BDD> bddvars;
    vector<int> input;
    vector<int> output;

    vector<string> variables;

    //new bdd constructer
    void construct_bdd_new();

    bool DFAflag = false;

    Cudd *mgr;

  protected:
  private:
    int nodes;
    vector<int> behaviour;
    vector<vector<int> > smtbdd;

    void read_from_file(string filename); //read the ltlf formula
    void read_partfile(string partfile); //read the partfile

    void print(vector<auto> v);

    bool strfind(string str, string target);

    string state2bin(int n);

    BDD var2bddvar(int v, int index);

    //new bdd constructer
    vector<vbdd> tBDD;

    vbdd try_get(int index);


  };
}

#endif // DFA_H
