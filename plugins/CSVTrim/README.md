# CSVTrim
# Language: R
# Input: TXT (keyword, value pairs)
# Output: CSV (trimmed file)
# Tested with: PluMA 1.1, R 4.0.0

PluMA plugin to take a CSV file and keep only the columns within a specific range.

The plugin accepts as input a TXT file with (keyword, value) pairs.  Three keywords are accepted:

inputfile: The name of the CSV file with the original data
start: Starting column to keep (default is 1, the first)
end: Ending column to keep (default is the last)

The output CSV file will be the original file, trimmed to this range.
