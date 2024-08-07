//
// Copyright (C) 2010-: Madhav P. Desai
// All Rights Reserved.
//  
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal with the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
// 
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimers.
//  * Redistributions in binary form must reproduce the above
//    copyright notice, this list of conditions and the following
//    disclaimers in the documentation and/or other materials provided
//    with the distribution.
//  * Neither the names of the AHIR Team, the Indian Institute of
//    Technology Bombay, nor the names of its contributors may be used
//    to endorse or promote products derived from this Software
//    without specific prior written permission.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR
// ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS WITH THE SOFTWARE.
#ifndef _rtl_Type__
#define _rtl_Type__

class rtlValue;
class hierRoot;

//
// types of rtl objects
//  
// base class
class rtlType: public hierRoot
{
  public:

  rtlType();

  virtual string Kind() {return("rtlType");}
  virtual int Size() {assert(0);}

  virtual string Get_Name();
  virtual string Get_C_Name() {assert(0);}
  virtual string Get_C_Dimension_String() {return("");}

  virtual rtlType* Get_Element_Type()
  {
    assert(0);
  }

  virtual int Get_Number_Of_Dimensions() {assert(0);}
  virtual int Get_Dimension(int I) {assert(0);}

  void Print(ostream& ofile);
  virtual void Print(ofstream& ofile);
  virtual void Print(string& ostring);

  virtual void Print_C_Struct_Field_Initialization(string prefix, rtlValue* v, ostream& ofile) {assert(0);}
  virtual void Print_C_Assignment_To_File(string dest, string src, ostream& ofile) {assert(0);}

  virtual bool Is_Scalar_Type() {return(false);}
};


//
// the 32 bit integer type.
// 
class rtlIntegerType: public rtlType
{
	int _low;
	int _high;
	public:
	rtlIntegerType(int low, int high);
	string Kind() {return("rtlInteger");}
  	virtual void Print(ostream& ofile);
  	virtual void Print_C_Struct_Field_Initialization(string prefix, rtlValue* v, ostream& ofile);
  	virtual string Get_C_Name() {return("integer");}
  	virtual bool Is_Scalar_Type() {return(true);}
	int Get_Low() {return(_low);}
	int Get_High() {return(_high);}
};


//
// The arbitrary precision unsigned type
//
class rtlUnsignedType: public rtlType
{
 protected:
  // width > 0
  int _width;

 public:
  virtual int Get_Width() {return(this->_width);}
  rtlUnsignedType(int width):rtlType() {_width = width;}

  virtual string Kind() {return("rtlUnsignedType");}
   
  virtual int Size() {return(this->_width);}
  virtual void Print(ostream& ofile);
  virtual void Print_C_Struct_Field_Initialization(string prefix, rtlValue* v, ostream& ofile);
  virtual string Get_C_Name() {return("bit_vector");}
  virtual bool Is_Scalar_Type() {return(true);}
};


//
// the arbitrary precision signed type
//
class rtlSignedType: public rtlUnsignedType
{
  // gets width from Unsigned

 public:

  rtlSignedType(int width):rtlUnsignedType(width) {}
  void Print(ostream& ofile);
  virtual string Kind() {return("rtlSignedType");}
};

//
// the array type
//   (multi-dimensional array of elements).
//
class rtlArrayType: public rtlType
{
  // multi-dimensional array types are possible
  vector<int> _dimensions;
  
  // element type..
  rtlType* _element_type;
 
 public:

  virtual string Kind() {return("rtlArrayType");}

  virtual int Get_Number_Of_Dimensions() {return(this->_dimensions.size());}
  virtual int Get_Dimension(int I)
	{
		if( (I >= 0) && (I < _dimensions.size()))
		{
			return(_dimensions[I]);
		}
		else
			return(0);
	}

  virtual rtlType* Get_Element_Type() {return(this->_element_type);}

  rtlArrayType(rtlType* element_type, vector<int>& dimensions);


  virtual int Size() 
  {
    int ret_val = this->Get_Element_Type()->Size();

    for(int i=0; i < this->Get_Number_Of_Dimensions(); i++)
      ret_val =  ret_val * this->_dimensions[i];

    return(ret_val);
  }


  virtual int Number_Of_Elements()
  {
    int ret_val = 1;
    for(int i=0; i < this->Get_Number_Of_Dimensions(); i++)
      ret_val = ret_val*(this->_dimensions[i]);
    return(ret_val);
  }

  virtual int Get_Index(vector<int> indices)
  {
	assert(indices.size() == _dimensions.size());

	int ret_val = 0;
	int S = 1;
	for(int I = _dimensions.size()-1; I >= 0; I--)
	{
		ret_val += (S*indices[I]);
		S = S*_dimensions[I];
	}
	return(ret_val);
  }

  virtual void Print(ostream& ofile);
  virtual void Print_C_Struct_Field_Initialization(string prefix, rtlValue* v, ostream& ofile);

  virtual string Get_C_Name() 
  {
	string ret_val = _element_type->Get_C_Name();
	return(ret_val);
  }

  virtual string Get_C_Dimension_String()
  {
	string ret_val;
	for(int I = 0, fI = _dimensions.size(); I < fI ; I++)
	{
		ret_val += "[" + IntToStr(_dimensions[I]) + "]" ;
	}
	return(ret_val);
  }

  virtual void Print_C_Assignment_To_File(string dest, string src, ostream& ofile);
};

//
// type manager... make types.
//
rtlType* Find_Or_Make_Integer_Type(int low_val, int high_val);
rtlType* Find_Or_Make_Unsigned_Type(int width);
rtlType* Find_Or_Make_Signed_Type(int width);
rtlType* Find_Or_Make_Array_Type(vector<int> dims, rtlType* element_type);

// each type is assigned an identifier.
string   Get_Type_Identifier(rtlType* t);

// print Vhdl type declarations.
void     Print_Vhdl_Type_Declarations(string prefix, ostream& ofile);

#endif
