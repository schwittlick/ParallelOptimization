import java.util.Random;

public class QuicksortMain {
	/**
	 * @param args
	 * @throws  
	 */
	public static void main(String[] args) {
		final int arrayLength = MyInput.getInt("Array length?", 10,	10000);
		final int maxRandom = MyInput.getInt(
				"Maximum random number for the array ", 0, 10000000);
		//int [] array = {15,51,33,41,84,36,88,96,76,8,68,95,43,59,92,17,84,42,90,84,74,83,65,43,33,41,84,36,88,96,33,41,84,36,88,96};
		//int[] array = {23, 12, 55, 94, 1, 12, 56, 22, 9, 76};
		int[] array = initArrayRandom(arrayLength, maxRandom);
		int[] array2 = copyArray(array);
		Quicksort app = new Quicksort(array2);
		app.run();
		new Thread(new QuicksortRunnable(array)).start();
	}
	
	private static int[] copyArray(int[] array) {
		int[] result = new int[array.length];
		for (int i = array.length - 1; 0 <= i; --i) {
			result[i] = array[i];
		}
		return result;
	}
	
	/**
	 * 
	 * @param arrayLength
	 * @param maxRandom
	 * @return
	 */
	private static int[] initArrayRandom(int arrayLength, int maxRandom) {
		int[] array = new int[arrayLength];
		Random random = new Random();
		for (int i = 0; i < array.length; i++) {
			array[i] = (int) random.nextInt(maxRandom);
		}
		return array;
	}
}
