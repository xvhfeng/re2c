#line 1 "../../../benchmarks/submatch_dfa_aot/src/ragel/iter_a_4.rl"
#include "ragel/common.c"

const char *delim = "\n";


#line 16 "../../../benchmarks/submatch_dfa_aot/src/ragel/iter_a_4.rl"



#line 12 "gen/ragel/iter_a_4-F1.c"
static const char _aaa_trans_keys[] = {
	1, 0, 2, 2, 2, 2, 2, 2,
	0, 2, 0, 2, 0
};

static const signed char _aaa_char_class[] = {
	0, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 2,
	0
};

static const signed char _aaa_index_offsets[] = {
	0, 0, 1, 2, 3, 6, 0
};

static const signed char _aaa_indicies[] = {
	2, 3, 4, 5, 0, 6, 8, 0,
	9, 0
};

static const signed char _aaa_index_defaults[] = {
	0, 0, 0, 0, 0, 0, 0
};

static const signed char _aaa_cond_targs[] = {
	0, 1, 2, 3, 4, 5, 1, 5,
	5, 1, 0
};

static const signed char _aaa_cond_actions[] = {
	0, 0, 0, 0, 0, 1, 2, 0,
	3, 4, 0
};

static const int aaa_start = 5;
static const int aaa_first_final = 5;
static const int aaa_error = 0;

static const int aaa_en_main = 5;


#line 18 "../../../benchmarks/submatch_dfa_aot/src/ragel/iter_a_4.rl"


static void lex(Input *in, Output *out)
{
	char *p = in->p;
	char *pe = in->pe;
	const char *s;
	int cs;
	
	
#line 74 "gen/ragel/iter_a_4-F1.c"
	{
		cs = (int)aaa_start;
	}
	
#line 27 "../../../benchmarks/submatch_dfa_aot/src/ragel/iter_a_4.rl"
	
	
#line 82 "gen/ragel/iter_a_4-F1.c"
	{
		unsigned int _trans = 0;
		const char * _keys;
		const signed char * _inds;
		int _ic;
		_resume: {}
		if ( p == pe )
			goto _out;
		_keys = ( _aaa_trans_keys + ((cs<<1)));
		_inds = ( _aaa_indicies + (_aaa_index_offsets[cs]));
		
		if ( ( (*( p))) <= 97 && ( (*( p))) >= 10 ) {
			_ic = (int)_aaa_char_class[(int)( (*( p))) - 10];
			if ( _ic <= (int)(*( _keys+1)) && _ic >= (int)(*( _keys)) )
				_trans = (unsigned int)(*( _inds + (int)( _ic - (int)(*( _keys)) ) )); 
			else
				_trans = (unsigned int)_aaa_index_defaults[cs];
		}
		else {
			_trans = (unsigned int)_aaa_index_defaults[cs];
		}
		
		cs = (int)_aaa_cond_targs[_trans];
		
		if ( _aaa_cond_actions[_trans] != 0 ) {
			
			switch ( _aaa_cond_actions[_trans] ) {
				case 2:  {
					{
#line 8 "../../../benchmarks/submatch_dfa_aot/src/ragel/iter_a_4.rl"
						
						outs(out, s, p);
						outc(out, '.');
						s = p;
					}
					
#line 119 "gen/ragel/iter_a_4-F1.c"
					
					
					break; 
				}
				case 4:  {
					{
#line 12 "../../../benchmarks/submatch_dfa_aot/src/ragel/iter_a_4.rl"
						s = p; }
					
#line 129 "gen/ragel/iter_a_4-F1.c"
					
					
					break; 
				}
				case 1:  {
					{
#line 8 "../../../benchmarks/submatch_dfa_aot/src/ragel/iter_a_4.rl"
						
						outs(out, s, p);
						outc(out, '.');
						s = p;
					}
					
#line 143 "gen/ragel/iter_a_4-F1.c"
					
					{
#line 13 "../../../benchmarks/submatch_dfa_aot/src/ragel/iter_a_4.rl"
						outc(out, '\n'); }
					
#line 149 "gen/ragel/iter_a_4-F1.c"
					
					
					break; 
				}
				case 3:  {
					{
#line 12 "../../../benchmarks/submatch_dfa_aot/src/ragel/iter_a_4.rl"
						s = p; }
					
#line 159 "gen/ragel/iter_a_4-F1.c"
					
					{
#line 13 "../../../benchmarks/submatch_dfa_aot/src/ragel/iter_a_4.rl"
						outc(out, '\n'); }
					
#line 165 "gen/ragel/iter_a_4-F1.c"
					
					
					break; 
				}
			}
			
		}
		
		if ( cs != 0 ) {
			p += 1;
			goto _resume;
		}
		_out: {}
	}
	
#line 28 "../../../benchmarks/submatch_dfa_aot/src/ragel/iter_a_4.rl"
	
	
	in->p = p;
	in->pe = pe;
}
