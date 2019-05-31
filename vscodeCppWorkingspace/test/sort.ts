var array: number[] = [3, 8, 2, 5, 1, 4, 7, 6];

quicksort(array, 0, 8);

for (var index:number = 0; index < array.length; index++) {
    console.log(array[index]);
}

function swap(array: number[], index1: number, index2: number):void {
    var tmp: number = array[index1]; 
    array[index1] = array[index2];
    array[index2] = tmp;
}

function quicksort(array:number[],left:number,right:number):void {    
    if (1 >= right) {
        return;
    }
    if (left < right) {
        var j: number = partition(array, left, right);
        quicksort(array, left, j - 1);
        quicksort(array, j + 1, right);
    }
}

function partition(array:number[],left:number,right:number):number {
    var pivot: number = array[left];
    var i: number = left + 1;

    for (var j: number = left + 1; j < right; j++){
        if (array[j] < pivot) {
            swap(array, j, i);
            i = i + 1;
        }
    }
    swap(array, left, i - 1);
    return i - 1;
}