// all the required parameters
const feedback = document.querySelector('.feedback');
const budgetFeedback = document.querySelector('.budget-feedback');
const expenseFeedback = document.querySelector('.expense-feedback');
// for the dashboard data 
const budgetAmount = document.getElementById('budget-amount');
const expenseAmount = document.getElementById('expense-amount');
const totalBalance = document.getElementById('total-amount');
// ------------------------------------------

// for budget form
const budgetForm = document.getElementById('budget-form');
const budgetInput = document.getElementById('budget-input');
const budgetSubmit = document.getElementById('budget-submit');
// ---------------------------------------

// for the expense form 
const expenseForm = document.getElementById('expense-form');
const expenseName = document.getElementById('expense-input');
const expenseValue = document.getElementById('expense-value');
const expenseSubmit = document.getElementById('expense-submit');

// ---------------------------------------------------

// for the list to show all the expenses
const expenseList = document.getElementById('expense-list');

// global variables
let itemList = [];  // to store expense details in object array
let itemId = 0;

// submit Budget method
function submitBudgetForm() {
    let value = budgetInput.value;
    if (value === "" || value < 0) {
        budgetFeedback.classList.add("show-feedback");
        budgetFeedback.innerHTML = `<p>The budget should not be empty or null!`;
        setTimeout(function () {
            budgetFeedback.classList.remove('show-feedback');
        }, 4000);
    }
    else {
        budgetAmount.textContent = value;
        budgetInput.value = "";
        showTotalBalance();
    }

}
function showTotalBalance() {
    const expense = totalExpense();
    // console.log(expense)
    const total = parseInt(budgetAmount.textContent) - expense;
    totalBalance.textContent = total;
    if (total < 0) {
        alert('your are in loss ');
    }
}



// submit expense method
function submitExpenseForm() {
    let name = expenseName.value;
    let value = expenseValue.value;
    if ((value === "" || value < 0) || name === "") {


        expenseFeedback.classList.add("show-feedback");
        expenseFeedback.innerHTML = `<p>The expense should not be empty or null!`;
        setTimeout(function () {
            expenseFeedback.classList.remove('show-feedback');
        }, 4000);
    }
    else {
        let amount = parseInt(value);
        expenseName.value = "";
        expenseValue.value = "";

        // create a object to store an expense details
        let expense = {
            id: itemId,
            title: name,
            amount: amount,
        }
        itemId++;
        itemList.push(expense);
        addExpense(expense);
        // show total balance
        showTotalBalance();

    }
}

function totalExpense() {
    let total = 0;
    if (itemList.length > 0) {

        total = itemList.reduce(function (acc, curr) {
            acc += curr.amount;
            return acc;
        }, 0);

    }
    expenseAmount.textContent = total;
    return total;
}

// add expense
function addExpense(expense) {
    const div = document.createElement('div');
    div.classList.add('expense');
    div.innerHTML = `<div class="expenses-list">
    <h6 class="expense-title">${expense.title}</h6>
    <h6 class="expense-amount">${expense.amount}</h6>
    <div class="expense-icon list-item">
        <a href="#" class="edit-icon" data-id="${expense.id}">
            <i>edit</i>
        </a>
        <a href="#" class="del-icon" data-id="${expense.id}">
            <i>delete</i>
        </a>
    </div>
</div>`;
    console.log(expense);
    expenseList.appendChild(div);
}

// edit expenses
function editElement(element) {
    let id = parseInt(element.dataset.id);
    let parent = element.parentElement.parentElement.parentElement;
    // console.log(parent);
    // remove from dom
    expenseList.removeChild(parent);
    let editExpense = itemList.filter(function (item) {
        return item.id === id;
    });

    expenseName.value = editExpense[0].title;
    expenseValue.value = editElement[0].amount;

    // remove from the list
    let tempList = itemList.filter(function (item) {
        return item.id != id;
    });
    // add remaining list to expenseList
    itemList = tempList;
    showTotalBalance();
}

// delete expenses
function deleteElement(element) {
    let id = parseInt(element.dataset.id);
    let parent = element.parentElement.parentElement.parentElement;
    // console.log(parent);
    // remove from dom
    expenseList.removeChild(parent);
    // remove from the list
    let tempList = itemList.filter(function (item) {
        return item.id != id;
    });
    // add remaining list to expenseList
    itemList = tempList;
    showTotalBalance();
}

// budget form submit
budgetForm.addEventListener('submit', function (e) {
    e.preventDefault();
    submitBudgetForm();
});
// expense form submit
expenseForm.addEventListener('submit', function (e) {
    e.preventDefault();
    submitExpenseForm();
});

// for icons
document.addEventListener('click', function (event) {
    if (event.target.parentElement.classList.contains('edit-icon')) {
        editElement(event.target.parentElement)
        // console.log('edit icon is clicked')
    }
    else if (event.target.parentElement.classList.contains('del-icon')) {
        deleteElement(event.target.parentElement);
        // console.log('delete icon is clicked')

    }
});