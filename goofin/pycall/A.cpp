#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <string>
#include </opt/miniconda3/include/python3.7m/Python.h>

using namespace std;

void exec_pycode(const char* code)
{
  Py_Initialize();
  PyRun_SimpleString(code);
  Py_Finalize();
}

int main()
{
	PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *presult;

  /*
  string str = "/opt/miniconda3";
  const char c[str.size() + 1];
  strcpy(c, str.c_str());
  Py_NoSiteFlag = 1;
  string str = "/opt/miniconda3";
  std::wstring widestr = std::wstring(str.begin(), str.end());
  const wchar_t* widecstr = widestr.c_str();
  Py_SetPythonHome(widecstr);
  wstring ws(Py_GetPath());
  string str2(ws.begin(), ws.end());
  cout << str2 << endl;
  cout << Py_GetPath() << endl;
  */
  Py_Initialize();
  PyRun_SimpleString("import sys");
  PyRun_SimpleString("sys.path.append('/opt/miniconda3/lib/python3.7/site-packages')");
  PyRun_SimpleString("from statsmodels.tsa.statespace.sarimax import SARIMAX;import numpy as np;model = SARIMAX(np.array([0.0] * 100), order=(1,0,1), seasonal_order=(2,0,3,7));fitted_model = model.fit(disp=False);print(9)");
  Py_Finalize();

	return 0;
}