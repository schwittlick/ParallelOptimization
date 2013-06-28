import java.util.Random;

public class QuicksortMain {
	private int[] array;
	
	/**
	 * @param args
	 * @throws  
	 */
	public static void main(String[] args) {
		/*final int arrayLength = MyInput.getInt("Array length? 10 - 100 ", 10,
				100);
		final int maxRandom = MyInput.getInt(
				"Maximum random number for the array ", 0, 10000000);*/
		int [] array = {15,51,33,41,84,36,88,96,76,8,68,95,43,59,92,17,84,42,90,84,74,83,65,43};
		Quicksort app = new Quicksort(array);
		//QuicksortThreaded paraApp = new QuicksortThreaded(array);
		
		//TODO Optimized Quicksort
		app.run();
	}
	
	/**
	 * 
	 * @param arrayLength
	 * @param maxRandom
	 * @return
	 */
	public int[] initArrayRandom(int arrayLength, int maxRandom) {
		int[] array = new int[arrayLength];
		Random random = new Random();
		for (int i = 0; i < array.length; i++) {
			array[i] = (int) random.nextInt(maxRandom);
		}
		return array;
	}
}
