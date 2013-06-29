/**
 * Timer allows to take time.
 * <p>The period is the difference from start of the timer
 * and the stop from the timer.<br/>
 * <code>System.currentTime()</code> sets the start value and the stop value.
 * </p>
 */
public class Timer {
	/**The start of the taken time in the timer.*/
	private long start;

	/**The stop of the taken time in the timer*/
	private long stop;

	/**
	 * Empty constructor.
	 */
	public Timer() {
		start();
	}

	/**
	 * Stops the timer.
	 * To stop the timer, the stop value will be saved from the current time.
	 * To use <code>stop</code>, <code>start</code> must be used before or 
	 * it will throw a exception.
	 *
	 * @throws an Exception on use <code>stop</code> then <code>start</code> were
	 * never used before.
	 */
	public void stop() {
		stop = System.currentTimeMillis();
	}

	/**
	 * Returns the taken time in the <code>Timer</code>.
	 * The taken time is the difference from start and stop.
	 *
	 * @return the difference from start and stop.
	 */
	public long getTime() {
		if (stop == 0) {
			return System.currentTimeMillis() - start;
		} else {
			return stop - start;
		}
	}

	/**
	 * Starts the timer.
	 * To start the timer, the start value will be saved from the current time.
	 */
	public void start() {
		start = System.currentTimeMillis();
	}
}
