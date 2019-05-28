

function add()
{
    let table = document.getElementById('record')
    let newRow   = table.insertRow(table.rows.length);
    let check = newRow.insertCell(0);
    check.innerHTML = "<input role='checkbox' name = 'box' type='checkbox' class='cbox checkbox'></input>"
    let id  = newRow.insertCell(1);   
    

    id.innerHTML = table.rows.length - 1
    for (let i = 2; i < 6; i++) {
        let tmp = newRow.insertCell(i)
        tmp.innerHTML = "<input type='text' value='  ' size='20' />";
    }
    let button = newRow.insertCell(6);
    button.innerHTML = "<input type='button' name='' onclick='save(this)' id=''  value='save' />"
}


function edit(obj)
{
    tr = obj.parentNode.parentNode;
    for (let i = 2; i < 6; i++) {
        tr.cells[i].innerHTML = "<input type='text' value='" + tr.cells[i].innerHTML + "' size='15' />";
    }
	tr.cells[6].innerHTML = "<input type='button' name='' onclick='save(this)' id=''  value='save' />"
}


function save(obj){
    let tr = obj.parentNode.parentNode; // 获取的本行的tr 
    for (let i = 2; i < 6; i++) {
        tr.cells[i].innerHTML = tr.cells[i].childNodes[0].value
    }
    tr.cells[6].innerHTML = "<input type='button' name='' onclick='edit(this)' id='' value='Edit' />"
}

function deleteRow(tableID)  {
    var table = document.getElementById(tableID);
    var rowCount = table.rows.length;

    // var i=1 to start after header
    for(var i = rowCount - 1; i >= 1; i--) {
        var row = table.rows[i];
        // index of td contain checkbox is 8
        var chkbox = row.cells[0].getElementsByTagName('input')[0];
        if('checkbox' == chkbox.type && true == chkbox.checked) {
            table.deleteRow(i);
         }
    }
}

function toggleAll(obj)
{
    let checkboxs = document.getElementsByName("box");
    for (let i = 0; i < checkboxs.length;i++) {
        checkboxs[i].checked = obj.checked;
    }
}