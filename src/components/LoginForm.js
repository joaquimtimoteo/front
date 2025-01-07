import React, { useState } from 'react';
import axios from 'axios';

const LoginForm = ({ setUserData }) => {
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');
  const [error, setError] = useState('');

  const handleSubmit = async (e) => {
    e.preventDefault();

    if (!email.trim() || !password.trim()) {
        setError('Por favor, preencha todos os campos.');
        return;
    }

    try {
        const response = await axios.post(
            'https://register-and-login-rebornxboot.onrender.com/api/user/signin',
            { email: email.trim(), password: password.trim() },
            {
                headers: {
                    'Content-Type': 'application/json',
                },
            }
        );

        if (response.data.access_token) {
            localStorage.setItem('access_token', response.data.access_token);
        }
        if (response.data.refresh_token) {
            localStorage.setItem('refresh_token', response.data.refresh_token);
        }

        setUserData(response.data); 
        setError(''); 
    } catch (err) {
        const errorDetail = err.response?.data?.detail;

        if (Array.isArray(errorDetail)) {
            setError(errorDetail.map((e) => e.msg).join(', '));
        } else if (typeof errorDetail === 'string') {
            setError(errorDetail);
        } else if (err.response?.status === 422) {
            setError('Dados inválidos fornecidos. Verifique e tente novamente.');
        } else {
            setError('Erro ao tentar fazer login.');
        }
    }
  };

  return (
    <div>
      <h2>Login</h2>
      {error && <p style={{ color: 'red' }}>{error}</p>}
      <form onSubmit={handleSubmit}>
        <div>
          <label>Email:</label>
          <input
            type="email"
            value={email}
            onChange={(e) => setEmail(e.target.value)}
            required
          />
        </div>
        <div>
          <label>Senha:</label>
          <input
            type="password"
            value={password}
            onChange={(e) => setPassword(e.target.value)}
            required
          />
        </div>
        <button type="submit">Entrar</button>
      </form>
    </div>
  );
};

export default LoginForm;
