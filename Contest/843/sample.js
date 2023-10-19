const fetchPromise = fetch('https://codeforces.com/api/user.rating?handle=Numinous');

console.log(fetchPromise);

fetchPromise.then((response) => (response.json()))
        .then((data) =>{
        console.log(data.result[data.result.length-1].newRating);
    });
console.log("Started request…");