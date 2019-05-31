var array = [3, 8, 2, 5, 1, 4, 7, 6];
quicksort(array, 0, 8);
for (var index = 0; index < array.length; index++) {
    console.log(array[index]);
}
function swap(array, index1, index2) {
    var tmp = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;
}
function quicksort(array, left, right) {
    if (1 >= right) {
        return;
    }
    if (left < right) {
        var j = partition(array, left, right);
        quicksort(array, left, j - 1);
        quicksort(array, j + 1, right);
    }
}
function partition(array, left, right) {
    var pivot = array[left];
    var i = left + 1;
    for (var j = left + 1; j < right; j++) {
        if (array[j] < pivot) {
            swap(array, j, i);
            i = i + 1;
        }
    }
    swap(array, left, i - 1);
    return i - 1;
}
