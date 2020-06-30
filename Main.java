import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Random;
import java.util.Arrays;

class InsertionDemo 
{
	public static void insertionSort(Integer A[])
	{ 
		for (int i = 1; i < A.length; i++) 
		{
			int key = A[i];
			int j = i - 1;
			while ((j >= 0) && (A[j] > key)) 
			{
				A[j + 1] = A[j];
				j--;
			}
			A[j + 1] = key;
		}
	}
	public static <T> void tampil(T data[]) 
	{
		System.out.println();
		System.out.println(Arrays.toString(data));
	}
} 
	
public class Main 
{
	public static void main(String[] args)
	{ 
		Integer A[] = {10,6,8,3,1};
		InsertionDemo.insertionSort(A);
		InsertionDemo.tampil(A);
	}
}