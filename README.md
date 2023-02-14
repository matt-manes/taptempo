# taptempo

Simple class to track the amount of time between "tap" events.<br>
The sample_rate is the number of times your "tap" source is checked per second.<br>
The tick() method should be called once every loop.<br>
The tempo can be obtained in Hertz or in samples using get_tempo_hz() and get_tempo_samples(), respectively.