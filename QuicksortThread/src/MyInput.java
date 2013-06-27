import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

/**
 * A class to handle inputs from the user on the terminal.
 * <p>
 * <code>MyInput</code> has static methods can be used in any other class, to
 * get the input which are defined in the methods by the names:
 * <ul>
 * <li><code>getText</code></li>
 * <li><code>getInt</code></li>
 * <li><code>getDouble</code></li>
 * </ul>
 * to handle 3 types of input. The private method <code>write</code> is used to
 * write on terminal as an alias for <code>System.out.print</code>.
 * <p>
 * <b>UPDATE</b></br> Update: 01.11.2012 -
 * <code>isBetween(value, min, max)</code> to check a value between two limits
 * for <code>Integer</code> and <code>Double</code><br/>
 * Update: 16.11.2012 - <code>getBoolean()</code> to get boolean input from the
 * user.<br/>
 * </p>
 * </p>
 * 
 * @author Dennis Haegler - s0532338
 * @version 1.0
 */
public class MyInput {

	/** Input from the terminal */
	private static InputStreamReader inputStream = new InputStreamReader(
			System.in);

	/** Buffered input from the terminal */
	private static BufferedReader input = new BufferedReader(inputStream);

	/**
	 * A empty private constructor.
	 * <p>
	 * Disable to create an object of the class <code>MyInput</code>. If the
	 * user needs to use the static methods from class <code>MyInput</code>,
	 * he/she must write the class name in front of the method severed by a dot.
	 * </p>
	 */
	private MyInput() {
	}

	/**
	 * Returns a text from input of the user.
	 * <p>
	 * Method use the method <code>getText(String requirement)</code>. The
	 * Method getText(String requirement) get an empty text from this method and
	 * send an text to this method which is typed in by the user.
	 * 
	 * @return a text from the input of the user.
	 */
	public static String getText() {
		return getText("");
	}

	/**
	 * Returns a text from an input of the user. Method will write an
	 * information for the user on the terminal which was given as String to the
	 * Method.
	 * 
	 * @param requirement
	 *            a String, in best case an information for the input.
	 * @return a text from the input of the user.
	 */
	public static String getText(String requirement) {
		String result = "";
		boolean inputOK = false;
		write(requirement);
		while (!inputOK) {
			try {
				result = input.readLine();
				inputOK = true;
			} catch (IOException ioe) {
			}
		}
		return result;
	}

	/**
	 * Returns an Integer from the input of user.
	 * <p>
	 * Uses the method getInt(String requirement) with an empty string sent to
	 * it.
	 * </p>
	 * 
	 * @return Returns an integer from the input of the user.
	 */
	public static int getInt() {
		return getInt("");
	}

	/**
	 * Returns an Integer from the input of user.
	 * 
	 * @return Returns an Integer from the input of user.
	 */
	public static int getInt(int min, int max) {
		return getInt("", min, max);
	}

	/**
	 * Returns an Integer by use the method getInt(String requirement, int min,
	 * int max).
	 * 
	 * @param requirement
	 *            a string to show the user informations for the input.
	 * @return Returns an integer from the input of the user.
	 */
	public static int getInt(String requirement) {
		return getInt(requirement, Integer.MIN_VALUE, Integer.MAX_VALUE);
	}

	/**
	 * Returns a Integer from an input of the user. Method parse a text from
	 * Method getText(String requirement) in an Integer. Only allowed inputs are
	 * numbers. If the user type a wrong input in the terminal, the request will
	 * be repeated.
	 * 
	 * @param requirement
	 *            a string to show the user informations for the input.
	 * @return Returns an integer from the input of the user.
	 */
	public static int getInt(String requirement, int min, int max) {
		int result = 0;
		boolean inputOK = false;
		while (!inputOK) {
			try {
				result = Integer.parseInt(getText(requirement));
				if (result >= min && result <= max)
					inputOK = true;
			} catch (NumberFormatException nfe) {
			}
		}
		return result;
	}

	/**
	 * Returns a value of double from the input of the user on the terminal.
	 * <p>
	 * The method use the method "getDouble(String requirement)" and to this
	 * Method an empty string and get a value of double from it. Wrong inputs
	 * will be handled in method "getDouble(String requirement)".
	 * </p>
	 */
	public static double getDouble() {
		return getDouble("");
	}

	/**
	 * Returns a value of double from the input of the user on the terminal.
	 */
	public static double getDouble(String requirement) {
		return getDouble(requirement, Double.MIN_VALUE, Double.MAX_VALUE);
	}

	/**
	 * Returns a value of double from the input of the user on the terminal.
	 * <p>
	 * The method uses the parameter, which is a string, to write it on the
	 * terminal. The string can be any text but it might be an information how
	 * to type the right things on the terminal for the user which will be use the
	 * program.
	 * </p>
	 * <b>Example:</b> "Please type in a value of double."
	 */
	public static double getDouble(String requirement, double min, double max) {
		double result = 0;
		boolean inputOK = false;
		while (!inputOK) {
			try {
				result = Double.parseDouble(getText(requirement));
				if (isBetween(result, min, max))
					inputOK = true;
			} catch (NumberFormatException nfe) {
				System.out.print("Please type in a double value.\n");
			}
		}
		return result;
	}

	/**
	 * Checks a value if it is between the min and max value.
	 * <p>
	 * The parameter min is the limit on the minimum side. The parameter max ist
	 * the limit on maximum side.
	 * </p>
	 * <p>
	 * Is the value equals min or max, or is the value bigger than min and
	 * smaller than max, the method returns a true. Otherwise it will be send a
	 * false.
	 * </p>
	 * 
	 * @param value
	 *            the value which will be checked if it is between min and max.
	 * @param min
	 *            the minimum limit in which the value has to be.
	 * @param max
	 *            the maximum limit in which the value has to be.
	 * @return <b>TRUE</b> - then the value is equals min or max, or bigger than
	 *         min and smaller than max.<br/>
	 *         <b>FALSE</b> - then value is smaller than min or bigger than max.
	 */
	public static boolean isBetween(int value, int min, int max) {
		int minValue;
		int maxValue;
		if (min > max) {
			minValue = max;
			maxValue = min;
		} else {
			minValue = min;
			maxValue = max;
		}
		return (value >= minValue && value <= maxValue);
	}

	/**
	 * Checks a value if it is between the min and max value.
	 * <p>
	 * The parameter min is the limit on the minimum side. The parameter max ist
	 * the limit on maximum side.
	 * </p>
	 * <p>
	 * Is the value equals min or max, or is the value bigger than min and
	 * smaler than max, the methode returns a true. Otherwise it will be send a
	 * false.
	 * </p>
	 * 
	 * @param value
	 *            the value which will be checked if it is between min and max.
	 * @param min
	 *            the minimum limit in which the value has to be.
	 * @param max
	 *            the maximum limit in which the value has to be.
	 * @return <b>TRUE</b> - then the value is equals min or max, or bigger than
	 *         min and smaller than max.<br/>
	 *         <b>FALSE</b> - then value is smaller than min or bigger than max.
	 */
	public static boolean isBetween(double value, double min, double max) {
		double minValue;
		double maxValue;
		if (min > max) {
			minValue = max;
			maxValue = min;
		} else {
			minValue = min;
			maxValue = max;
		}
		return (value >= minValue && value <= maxValue);
	}

	/**
	 * Returns a boolean from user's input. Read the input.<br/>
	 * <p>
	 * Returns <code>TRUE</code> on:
	 * <ul>
	 * <li>yes</li>
	 * <li>y</li>
	 * <li>1</li>
	 * <li>true</li>
	 * </ul>
	 * Returns <code>FALSE</code> on:
	 * <ul>
	 * <li>no</li>
	 * <li>n</li>
	 * <li>0</li>
	 * <li>false</li>
	 * </ul>
	 * </p>
	 * Case sensitive will be ignored on the inputs.
	 * 
	 * @param requirement
	 *            An information for the user to inform about the input.
	 */
	public static boolean getBoolean(String requirement) {
		boolean result = false;
		String answer;
		answer = getText(requirement);
		if (answer.equalsIgnoreCase("true") || answer.equalsIgnoreCase("yes")
				|| answer.equalsIgnoreCase("y") || answer.equalsIgnoreCase("1")) {
			result = true;
		} else if (answer.equalsIgnoreCase("false")
				|| answer.equalsIgnoreCase("no")
				|| answer.equalsIgnoreCase("n") || answer.equalsIgnoreCase("0")) {
			result = false;
		} else {
			write("Your input is wrong.\n");
			writeOptionsForBooleanInput();
			result = getBoolean("Your input ");
		}
		return result;
	}

	/**
	 * Fills a string up with dots by the given length.
	 * <p>
	 * Is the string smaller than the <code>toLength</code> parameter, it will
	 * be get dot until the string is as long as the <code>toLength</code>
	 * parameter.
	 * </p>
	 */
	private static String fillWithDots(String string, int toLength) {
		String result = string;
		while (result.length() < toLength) {
			result = result + ".";
		}
		return result;
	}

	/**
	 * Writes information on the terminal for the user to inform him, how a
	 * right input have to look like.
	 */
	private static void writeOptionsForBooleanInput() {
		String yes = "for yes";
		String no = "for no";
		String yesOrNo = "[yes|no]";
		String format = "%5s %-15s %-8s";
		yes = fillWithDots(yes, 15);
		no = fillWithDots(no, 15);
		System.out.printf("%-10s\n", "Please typ in:");
		System.out.printf(format + "\n", " ", yes, "[yes | true  |  1]");
		System.out.printf(format + "\n", " ", no, "[no  | false |  0]");
	}

	/**
	 * Helping method to write on the terminal. Method writes text on the
	 * terminal by using <code>print</code> from <code>System.out</code>.
	 * 
	 * @param text
	 *            is a string which will be written on the terminal.
	 */
	private static void write(String text) {
		System.out.print(text);
	}
}
