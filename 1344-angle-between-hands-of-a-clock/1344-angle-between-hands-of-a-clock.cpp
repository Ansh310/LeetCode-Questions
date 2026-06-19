class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Use double to prevent losing decimal precision
        double hourPosition = ((hour * 5) % 60) + (((double)minutes / 60) * 5);

        // Calculate absolute difference between position units
        double diff = abs(hourPosition - minutes);

        // Convert the minute-unit difference to degrees (6 degrees per minute unit)
        double angle = diff * 6;

        // Return the smaller angle
        return angle > 180 ? 360 - angle : angle;
    }
};
