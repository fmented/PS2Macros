#ifndef EVENT_TO_HID_H
#define EVENT_TO_HID_H

#include  "keytab.h"
#include  "com.h"


event_hid(int x){
  switch (x){
    case(	32	):			//	[Space]	
    pressKey(0,SPACE);
    break;
    case(	33	):			//	[!]	
    pressKey(SHIFT,K1);
    break;
    case(	34	):			//	["]	
    pressKey(SHIFT,QUOTE);
    break;
    case(	35	):			//	[#]	
    pressKey(SHIFT,K3);
    break;
    case(	36	):			//	[$]	
    pressKey(SHIFT,K4);
    break;
    case(	37	):			//	[%]	
    pressKey(SHIFT,K5);
    break;
    case(	38	):			//	[&]	
    pressKey(SHIFT,K7);
    break;
    case(	39	):			//	[']	
    pressKey(0,QUOTE);
    break;
    case(	40	):			//	[(]	
    pressKey(SHIFT,K9);
    break;
    case(	41	):			//	[)]	
    pressKey(SHIFT,K0);
    break;
    case(	42	):			//	[*]	
    pressKey(SHIFT,K8);
    break;
    case(	43	):			//	[+]	
    pressKey(SHIFT,EQUAL);
    break;
    case(	44	):			//	[,]	
    pressKey(0,COMMA);
    break;
    case(	45	):			//	[-]	
    pressKey(0,SUBTRACT);
    break;
    case(	46	):			//	[.]	
    pressKey(0,PERIOD);
    break;
    case(	47	):			//	[/]	
    pressKey(0,FSLASH);
    break;
    case(	48	):			//	[0]	
    pressKey(0,K0);
    break;
    case(	49	):			//	[1]	
    pressKey(0,K1);
    break;
    case(	50	):			//	[2]	
    pressKey(0,K2);
    break;
    case(	51	):			//	[3]	
    pressKey(0,K3);
    break;
    case(	52	):			//	[4]	
    pressKey(0,K4);
    break;
    case(	53	):			//	[5]	
    pressKey(0,K5);
    break;
    case(	54	):			//	[6]	
    pressKey(0,K6);
    break;
    case(	55	):			//	[7]	
    pressKey(0,K7);
    break;
    case(	56	):			//	[8]	
    pressKey(0,K8);
    break;
    case(	57	):			//	[9]	
    pressKey(0,K9);
    break;
    case(	58	):			//	[:]	
    pressKey(SHIFT,SEMICOLON);
    break;
    case(	59	):			//	[;]	
    pressKey(0,SEMICOLON);
    break;
    case(	60	):			//	[<]	
    pressKey(SHIFT,COMMA);
    break;
    case(	61	):			//	[=]	
    pressKey(0,EQUAL);
    break;
    case(	62	):			//	[>]	
    pressKey(SHIFT,PERIOD);
    break;
    case(	63	):			//	[?]	
    pressKey(SHIFT,FSLASH);
    break;
    case(	64	):			//	[@]	
    pressKey(SHIFT,K2);
    break;
    case(	65	):			//	[A]	
    pressKey(SHIFT,A);
    break;
    case(	66	):			//	[B]	
    pressKey(SHIFT,B);
    break;
    case(	67	):			//	[C]	
    pressKey(SHIFT,C);
    break;
    case(	68	):			//	[D]	
    pressKey(SHIFT,D);
    break;
    case(	69	):			//	[E]	
    pressKey(SHIFT,E);
    break;
    case(	70	):			//	[F]	
    pressKey(SHIFT,F);
    break;
    case(	71	):			//	[G]	
    pressKey(SHIFT,G);
    break;
    case(	72	):			//	[H]	
    pressKey(SHIFT,H);
    break;
    case(	73	):			//	[I]	
    pressKey(SHIFT,I);
    break;
    case(	74	):			//	[J]	
    pressKey(SHIFT,J);
    break;
    case(	75	):			//	[K]	
    pressKey(SHIFT,K);
    break;
    case(	76	):			//	[L]	
    pressKey(SHIFT,L);
    break;
    case(	77	):			//	[M]	
    pressKey(SHIFT,M);
    break;
    case(	78	):			//	[N]	
    pressKey(SHIFT,N);
    break;
    case(	79	):			//	[O]	
    pressKey(SHIFT,O);
    break;
    case(	80	):			//	[P]	
    pressKey(SHIFT,P);
    break;
    case(	81	):			//	[Q]	
    pressKey(SHIFT,Q);
    break;
    case(	82	):			//	[R]	
    pressKey(SHIFT,R);
    break;
    case(	83	):			//	[S]	
    pressKey(SHIFT,S);
    break;
    case(	84	):			//	[T]	
    pressKey(SHIFT,T);
    break;
    case(	85	):			//	[U]	
    pressKey(SHIFT,U);
    break;
    case(	86	):			//	[V]	
    pressKey(SHIFT,V);
    break;
    case(	87	):			//	[W]	
    pressKey(SHIFT,W);
    break;
    case(	88	):			//	[X]	
    pressKey(SHIFT,X);
    break;
    case(	89	):			//	[Y]	
    pressKey(SHIFT,Y);
    break;
    case(	90	):			//	[Z]	
    pressKey(SHIFT,Z);
    break;
    case(	91	):			//	[[]	
    pressKey(0,LBRACKET);
    break;
    case(	92	):			//	[\]	
    pressKey(0,BSLASH);
    break;
    case(	93	):			//	[]]	
    pressKey(0,RBRACKET);
    break;
    case(	94	):			//	[^]	
    pressKey(SHIFT,K6);
    break;
    case(	95	):			//	[_]	
    pressKey(SHIFT,SUBTRACT);
    break;
    case(	96	):			//	[`]	
    pressKey(0,GRAVE);
    break;
    case(	97	):			//	[a]	
    pressKey(0,A);
    break;
    case(	98	):			//	[b]	
    pressKey(0,B);
    break;
    case(	99	):			//	[c]	
    pressKey(0,C);
    break;
    case(	100	):			//	[d]	
    pressKey(0,D);
    break;
    case(	101	):			//	[e]	
    pressKey(0,E);
    break;
    case(	102	):			//	[f]	
    pressKey(0,F);
    break;
    case(	103	):			//	[g]	
    pressKey(0,G);
    break;
    case(	104	):			//	[h]	
    pressKey(0,H);
    break;
    case(	105	):			//	[i]	
    pressKey(0,I);
    break;
    case(	106	):			//	[j]	
    pressKey(0,J);
    break;
    case(	107	):			//	[k]	
    pressKey(0,K);
    break;
    case(	108	):			//	[l]	
    pressKey(0,L);
    break;
    case(	109	):			//	[m]	
    pressKey(0,M);
    break;
    case(	110	):			//	[n]	
    pressKey(0,N);
    break;
    case(	111	):			//	[o]	
    pressKey(0,O);
    break;
    case(	112	):			//	[p]	
    pressKey(0,P);
    break;
    case(	113	):			//	[q]	
    pressKey(0,Q);
    break;
    case(	114	):			//	[r]	
    pressKey(0,R);
    break;
    case(	115	):			//	[s]	
    pressKey(0,S);
    break;
    case(	116	):			//	[t]	
    pressKey(0,T);
    break;
    case(	117	):			//	[u]	
    pressKey(0,U);
    break;
    case(	118	):			//	[v]	
    pressKey(0,V);
    break;
    case(	119	):			//	[w]	
    pressKey(0,W);
    break;
    case(	120	):			//	[x]	
    pressKey(0,X);
    break;
    case(	121	):			//	[y]	
    pressKey(0,Y);
    break;
    case(	122	):			//	[z]	
    pressKey(0,Z);
    break;
    case(	123	):			//	[{]	
    pressKey(SHIFT,LBRACKET);
    break;
    case(	124	):			//	[|]	
    pressKey(SHIFT,BSLASH);
    break;
    case(	125	):			//	[}]	
    pressKey(SHIFT,RBRACKET);
    break;
    case(	126	):			//	[~]	
    pressKey(SHIFT,GRAVE);
    break;

	}
}




void wordKey(String w){
  int n = w.length()+1;
  char words[n];
  w.toCharArray(words,n);
  words[n]=(int)words[n];
  for (int i=0; i < n-1; i++){
    
      event_hid(words[i]);
    delay(1);
  }
}

#endif
