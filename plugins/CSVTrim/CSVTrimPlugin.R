input <- function(inputfile) {
  parameters <- read.table(inputfile, as.is=T);
  rownames(parameters) <- parameters[,1]
  my_data <<- read.csv(toString(parameters["inputfile",2]), header = T)
  start_column <<- as.integer(parameters["start", 2])
  if (is.na(start_column)) {
     start_column <<- 1
  }
  end_column <<- as.integer(parameters["end", 2]);
  if (is.na(end_column)) {
     end_column <<- ncol(my_data);
  }
}

run <- function() {
   my_data <<- my_data[,start_column:end_column];
}

output <- function(outputfile) {
   write.table(my_data, file=outputfile, sep=",", append=FALSE, row.names=FALSE, col.names=TRUE)
}
