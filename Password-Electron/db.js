const sqlite3 = require('sqlite3').verbose();

let db = new sqlite3.Database('pass.db', (err) => {
  if (err) {
    console.error(err.message);
  }
  console.log('Connected to the pass database.');
});

// db.serialize(() => {
//     db.each(`SELECT PlaylistId as id,
//                     Name as name
//              FROM playlists`, (err, row) => {
//       if (err) {
//         console.error(err.message);
//       }
//       console.log(row.id + "\t" + row.name);
//     });
//   });

db.run('create table list(id integer, addr text, user text, password text, remark text)', (err)=> {
    if (err) {
        console.log(err.message);
    }
    console.log('create table success.');
})

db.close((err) => {
  if (err) {
    return console.error(err.message);
  }
  console.log('Close the database connection.');
});