#include <stdio.h>
#include <assert.h>

struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  struct CountsByUsage counts = {0, 0, 0};
  for(int i=0;i<nBatteries;i++)
  {
    if(cycles[i]<310)
      counts.lowcount++;
    else if(310<=cycles[i]<=929)
      counts.mediumcount++;
    else
      counts.highcount++;
    
  }
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300, 500, 600, 900, 1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  printf("Low count:%d\n",counts.lowcount);
   printf("Medium count:%d\n",counts.mediumcount);
  printf("High count:%d\n",counts.highcount);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByNumberOfCycles();
  return 0;
}
