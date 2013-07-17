import java.util.Random;

public class QuicksortMain {
	/**
	 * @param args
	 * @throws  
	 */
	public static void main(String[] args) {
		final int arrayLength = MyInput.getInt("Array length?", 10,	10000000);
		final int maxRandom = MyInput.getInt(
				"Maximum random number for the array ", 0, 10000000);
		//int [] array = {15,51,33,41,84,36,88,96,76,8,68,95,43,59,92,17,84,42,90,84,74,83,65,43,33,41,84,36,88,96,33,41,84,36,88,96};
		//int[] array = {23, 12, 55, 94, 1, 12, 56, 22, 9, 76};
		int[] array = initArrayRandom(arrayLength, maxRandom);
		int[] array2 = copyArray(array);
		System.out.println("Starting to Sort.");
		Quicksort app = new Quicksort(array2);
		System.out.println("Is Sorted: " + app.isSorted());
		Timer timer = new Timer();
		app.run();
		timer.stop();
		System.out.println("Is Sorted: " + app.isSorted());
		System.out.println("Ended to Sort. Time needed: " + timer.getTime() + "ms");
		
		//TODO keep Thread alive until all inner threads died
		//Thread thread = new Thread(new QuicksortRunnable(array));
		//System.out.println("Starting to Thread.");
		//thread.start();
		//thread.join();
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
	
	/**
	 * 
	 * @param array
	 */
	private static void print(int[] array) {
		for (int i = 0; i < array.length; i++) {
			System.out.printf("%3d :", i);
		}
		System.out.println("");
		for (int i = 0; i < array.length; i++) {
			System.out.printf("%3d :", array[i]);
		}
		System.out.println("");
	}
}
