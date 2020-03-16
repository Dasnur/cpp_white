#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <sstream>
using namespace std;

void    free_all(int **res, int h)
{
    for (int j = 0; j < h; j++)
	{
		if (res[j])
		{
        	free(res[j]);
			res[j] = NULL;
		}
	}
}

class   Matrix
{
public:
    Matrix()
    {
		h = 0;
		w = 0;
		m = NULL;
	}
    Matrix(int num_rows, int num_cols)
    {
		if (num_rows < 0 || num_cols < 0)
			throw out_of_range("");
        h = num_rows;
        w = num_cols;
		SetMatrix(h, w);
    }

	void	SetMatrix(int hn, int wn)
	{
		h = hn;
		w = wn;
		int j = 0;
		int i = 0;
		m = (int **)malloc(sizeof(int*) * h);
        while (j < h)
        {
            m[j] = (int *)malloc(sizeof(int) * w);
			i = 0;
            while (i < w)
            {
                m[j][i] = 0;
                i++;
            }
            j++;
        }
	}

	int		GetNumRows() const
	{
		return h;
	}

	int		GetNumColumns() const{
		return w;
	}
    void    Reset(int nh, int nw)
    {
		if (nh < 0 || nw < 0)
			throw out_of_range("");
        int i = 0;
        int j = 0;
        if (m)
        {
            free_all(m, h);
            free(m);
			m = NULL;
        }
        h = nh;
        w = nw;
        m = (int **)malloc(sizeof(int*) * h);
        while (j < h)
        {
            m[j] = (int *)malloc(sizeof(int) * w);
			i = 0;
            while (i < w)
            {
                m[j][i] = 0;
                i++;
            }
            j++;
        }
    }
	void	GetLine(int j, int i, ostream& in) const
	{
		int a = 0;
		while (a < i)
		{
			if (a > 0)
				in << " " << m[j][a];
			else
				in << m[j][a];
			a++;
		}
		in << endl;
	}

	void	SetNum(int val, int j, int i)
	{
		m[j][i] = val;
	}

	int		&At(int j, int i) {
		if (i >= w || j >= h || i < 0 || j < 0)
			throw out_of_range("");
		return (m[j][i]);
	}

	int		At(int j, int i) const {
		if (i >= w || j >= h || j < 0 || i < 0)
			throw out_of_range("");
		return (m[j][i]);
	}

private:
    int h;
    int w;
    int **m;
};

ostream&	operator<<(ostream& in, const Matrix m)
{
	int i = 0;
	in << m.GetNumRows() <<  " " << m.GetNumColumns() << endl;
	while (i < m.GetNumRows())
	{
		m.GetLine(i, m.GetNumColumns(), in);
		i++;
	}
	return in;
}

istream&	operator>>(istream& in, Matrix& m)
{
	int n;
	int k;
	int i= 0;
	int j = 0;
	int tmp;
	in >> n >> k;
	m.SetMatrix(n, k);
	stringstream ss;
	string line;
	while (j < n)
	{
		i = 0;
		while (i < k)
		{
			in >> tmp;
			m.SetNum(tmp, j, i);
			i++;
		}
		j++;
	}
	return in;
}

bool	compare_mat(const Matrix &m1, const Matrix &m2)
{
	int i= 0;
	int j = 0;
	while (j < m1.GetNumRows())
	{
		i = 0;
		while (i < m1.GetNumColumns())
		{
			if (m1.At(j, i) == m2.At(j, i))
				i++;
			else
				return false;
		}
		j++;
	}
	return true;
}

bool	operator==(const Matrix &m1, const Matrix &m2)
{
	if ((m1.GetNumColumns() == m2.GetNumColumns()) && (m1.GetNumRows() == m2.GetNumRows()))
	{
		if (compare_mat(m1, m2))
			return true;
	}
	if ((m1.GetNumColumns() == 0 || m1.GetNumRows() == 0) && (m2.GetNumColumns() == 0 || m2.GetNumRows() == 0))
		return true;
	return false;
}

Matrix	operator+(const Matrix &m1, const Matrix &m2)
{
	if ((m1.GetNumColumns() == m2.GetNumColumns()) && (m1.GetNumRows() == m2.GetNumRows()))
	{
		int j = 0;
		int i = 0;
		Matrix res(m1.GetNumRows(), m1.GetNumColumns());
		while (j < m1.GetNumRows())
		{
			i = 0;
			while (i < m1.GetNumColumns())
			{
				res.SetNum((m1.At(j, i) + (m2.At(j, i))), j, i);
				i++;
			}
			j++;
		}
		return (res);
	}
	else if ((m1.GetNumColumns() == 0 || m1.GetNumRows() == 0) && (m2.GetNumColumns() == 0 || m2.GetNumRows() == 0))
	{
		Matrix res;
		return (res);
	}
	else
		throw invalid_argument("wrong size");
}
